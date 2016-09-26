#include "ProviderDAO.h"
#include <QSqlQuery>
#include <QVariant>

ProviderDAO::ProviderDAO(): DAO("Provider")
{
    addMapping("Name", "NAME", "varchar");
    createTable();
}

ProviderDAO* ProviderDAO::getInstance()
{
    static ProviderDAO instance;
    return &instance;
}

Persistable* ProviderDAO::createObject(int id) {
    return new Provider(id);
}
