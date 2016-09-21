#include "ProviderDAO.h"
#include <QSqlQuery>
#include <QVariant>

ProviderDAO::ProviderDAO(): DAO("Provider") {
    createTable();
}

ProviderDAO* ProviderDAO::getInstance()
{
    static ProviderDAO instance;
    return &instance;
}

Provider* ProviderDAO::load(int id) const
{
    QSqlQuery query;
    query.exec(tr("select Name from %1 where id = %2")
               .arg(getTableName())
               .arg(id));
    return query.next() ? new Provider(id, query.value(0).toString())
                        : 0;
}

void ProviderDAO::createTable()
{
    QSqlQuery query;
    query.exec(tr("create table %1 ( \
                    ID      int primary key, \
                    Name    varchar \
                )").arg(getTableName()));
}

void ProviderDAO::update(Persistable* persistable)
{
    Provider* provider = static_cast<Provider*>(persistable);
    QSqlQuery query;
    query.exec(tr("update %1 set Name = \"%2\" where ID = %3")
               .arg(getTableName())
               .arg(provider->getName())
               .arg(provider->getID()));
}

void ProviderDAO::insert(Persistable* persistable)
{
    Provider* provider = static_cast<Provider*>(persistable);
    QSqlQuery query;
    query.exec(tr("insert into %1 values(%2, \"%3\")")
               .arg(getTableName())
               .arg(provider->getID())
               .arg(provider->getName()));
}
