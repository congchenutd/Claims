#include "DAO.h"
#include "Persistable.h"
#include <QSqlQuery>
#include <QVariant>

/**
 * Save the given persistable into database
 */
void DAO::save(Persistable* persistable)
{
    if (exists(persistable))
        update(persistable);
    else
        insert(persistable);
}

/**
 * @return  whether the given persistale exists in the database
 */
bool DAO::exists(Persistable* persistable) const
{
    QSqlQuery query;
    query.exec(tr("select * from %1 where ID = %2")
               .arg(_tableName)
               .arg(persistable->getID()));
    return query.next();
}

/**
 * Remove the given persistable and its relations from the database
 */
void DAO::remove(Persistable* persistable)
{
    QSqlQuery query;
    query.exec(tr("delete from %1 where ID = %2")
               .arg(_tableName)
               .arg(persistable->getID()));

    removeRelationships(persistable);
}

QString DAO::getTableName() const {
    return _tableName;
}

int DAO::getNextID() const
{
    QSqlQuery query;
    query.exec(tr("select max(ID) from %1").arg(getTableName()));
    return query.next() ? query.value(0).toInt() + 1 : 1;
}

/**
 * Update the relationships of a persistable
 */
void DAO::updateRelationships(Persistable* persistable)
{
    removeRelationships(persistable);
    insertRelationships(persistable);
}

void DAO::addRelationships(const Relationship& relationship) {
    _relationships << relationship;
}

QList<Relationship> DAO::getAllRelationships() const {
    return _relationships;
}

void DAO::createRelationshipTables()
{
    QSqlQuery query;
    foreach (const Relationship& relationship, getAllRelationships())
        query.exec(tr("create table %1 ( \
                      %2 int references %3 (ID) on delete cascade on update cascade, \
                      %4 int references %5 (ID) on delete cascade on update cascade, \
                      primary key (%2, %4) \
               )").arg(relationship.getRelationshipTableName())
                  .arg(relationship.getMainID())
                  .arg(relationship.getMainTableName())
                  .arg(relationship.getForeignID())
                  .arg(relationship.getForeignTableName())
             );
}


void DAO::removeRelationships(Persistable* persistable)
{
    QSqlQuery query;
    foreach (const Relationship& relationship, getAllRelationships())
        query.exec(tr("delete from %1 where %2 = %3)")
                    .arg(relationship.getRelationshipTableName())
                    .arg(relationship.getMainID())
                    .arg(persistable->getID())
             );
}
