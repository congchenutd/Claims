#include "ClaimResult.h"
#include "Deposit.h"
#include "DepositDAO.h"

Deposit::Deposit(int id)
    : Attachable(id, DepositDAO::getInstance()),
      _result(0)
{
}

QDate Deposit::getDate() const {
    return _date;
}

void Deposit::setDate(const QDate& date) {
    _date = date;
}

double Deposit::getAmount() const {
    return _amount;
}

void Deposit::setAmount(double amount) {
    _amount = amount;
}

ClaimResult* Deposit::getClaimResult() {
    return _result;
}

void Deposit::setClaimResult(ClaimResult* result) {
    _result = result;
}
