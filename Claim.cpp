#include "Claim.h"
#include "ClaimDAO.h"

Claim::Claim(int id)
    : Attachable (id, ClaimDAO::getInstance()),
      _invoice(0),
      _result(0)
{}

QString Claim::getClaimee() const {
    return _claimee;
}

void Claim::setClaimee(const QString& source) {
    _claimee = source;
}

QString Claim::getClaimID() const {
    return _claimID;
}

void Claim::setClaimID(const QString& claimID) {
    _claimID = claimID;
}

QDate Claim::getDate() const {
    return _date;
}

void Claim::setDate(const QDate& date) {
    _date = date;
}

Invoice* Claim::getInvoice() const {
    return _invoice;
}

void Claim::setInvoice(Invoice* invoice) {
    _invoice = invoice;
}

ClaimResult* Claim::getClaimResult() const {
    return _result;
}

void Claim::setClaimResult(ClaimResult* result) {
    _result = result;
}
