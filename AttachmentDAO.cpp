#include "AttachmentDAO.h"
#include <QSqlQuery>
#include <QVariant>

AttachmentDAO::AttachmentDAO(): DAO("Attachment") {
    createTable();
}

AttachmentDAO* AttachmentDAO::getInstance()
{
    static AttachmentDAO instance;
    return &instance;
}

Attachment* AttachmentDAO::load(int id) const
{
    QSqlQuery query;
    query.exec(tr("select Title, FilePath from %1 where id = %2")
               .arg(getTableName())
               .arg(id));
    return query.next() ? new Attachment(id, query.value(0).toString(), query.value(1).toString())
                        : 0;
}

void AttachmentDAO::createTable()
{
    QSqlQuery query;
    query.exec(tr("create table %1 ( \
                    ID          int primary key, \
                    Title       varchar, \
                    FilePath    varchar \
                )").arg(getTableName()));
}

void AttachmentDAO::update(Persistable* persistable)
{
    Attachment* attachment = static_cast<Attachment*>(persistable);
    QSqlQuery query;
    query.exec(tr("update %1 set Name = \"%2\", FilePath = \"%3\" where ID = %4")
               .arg(getTableName())
               .arg(attachment->getTitle())
               .arg(attachment->getFilePath())
               .arg(attachment->getID()));
}

void AttachmentDAO::insert(Persistable* persistable)
{
    Attachment* attachment = static_cast<Attachment*>(persistable);
    QSqlQuery query;
    query.exec(tr("insert into %1 values(%2, \"%3\", \"%4\")")
               .arg(getTableName())
               .arg(attachment->getID())
               .arg(attachment->getTitle())
               .arg(attachment->getFilePath()));
}
