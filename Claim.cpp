#include "Claim.h"

Claim::Claim(int id, const QString& source, const QString& claimID, const QDate& date, Invoice* invoice)
    : Attachable (id, 0),
      _source(source),
      _claimID(claimID),
      _date(date),
      _invoice(invoice),
      _result(0)
{}

QString Claim::getSource() const {
    return _source;
}

void Claim::setSource(const QString& source) {
    _source = source;
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

ClaimResult* Claim::getResult() const {
    return _result;
}

void Claim::setResult(ClaimResult* result) {
    _result = result;
}
