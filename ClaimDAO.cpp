#include "ClaimDAO.h"

#include <QSqlQuery>

ClaimDAO::ClaimDAO()
    : AttachableDAO("Claim")
{
    addMapping("Claimee",   "CLAIMEE",  "varchar");
    addMapping("ClaimID",   "CLAIMID",  "varchar");
    addMapping("Date",      "DATE",     "date");
    addRelationships(Relationship("Claim", "Invoice"));
    addRelationships(Relationship("Claim", "ClaimResult"));
    createTable();
}

ClaimDAO* ClaimDAO::getInstance()
{
    static ClaimDAO instance;
    return &instance;
}

Persistable* ClaimDAO::createObject(int id) {
    return new Claim(id);
}
