#include "ClaimResult.h"

ClaimResult::ClaimResult(int id)
    : Attachable (id, 0),
      _claim(0)
{

}

QDate ClaimResult::getDate() const {
    return _date;
}

void ClaimResult::setDate(const QDate& date) {
    _date = date;
}

double ClaimResult::getPaidAmount() const {
    return _paidAmount;
}

void ClaimResult::setPaidAmount(double amount) {
    _paidAmount = amount;
}

QString ClaimResult::getState() const {
    return _state;
}

void ClaimResult::setState(const QString& state) {
    _state = state;
}

Claim* ClaimResult::getClaim() const {
    return _claim;
}

void ClaimResult::setClaim(Claim* claim) {
    _claim = claim;
}
