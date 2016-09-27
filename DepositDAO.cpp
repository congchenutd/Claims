#include "Deposit.h"
#include "DepositDAO.h"

DepositDAO::DepositDAO()
    : AttachableDAO("Deposit")
{
    addMapping("Date",      "DATE",     "date");
    addMapping("Amount",    "AMOUNT",   "double");
    addRelationships(Relationship("Deposit", "ClaimResult"));
    createTable();
}

DepositDAO* DepositDAO::getInstance()
{
    static DepositDAO instance;
    return &instance;
}

Persistable* DepositDAO::createObject(int id) {
    return new Deposit(id);
}
