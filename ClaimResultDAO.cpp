#include "ClaimResult.h"
#include "ClaimResultDAO.h"
#include <QSqlQuery>

ClaimResultDAO::ClaimResultDAO()
    : AttachableDAO("ClaimResult")
{
    addMapping("Date",          "DATE",         "date");
    addMapping("PaidAmount",    "PAIDAMOUNT",   "double");
    addMapping("State",         "STATE",        "varchar");
    createTable();
}

ClaimResultDAO* ClaimResultDAO::getInstance()
{
    static ClaimResultDAO instance;
    return &instance;
}

Persistable* ClaimResultDAO::createObject(int id) {
    return new ClaimResult(id);
}
