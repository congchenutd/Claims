#ifndef CLAIM_H
#define CLAIM_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class Invoice;
class ClaimResult;

class Claim: public Attachable
{
public:
    Claim(int id, const QString& source, const QString& claimID, const QDate& date, Invoice* invoice);

    QString getSource() const;
    void setSource(const QString& source);

    QString getClaimID() const;
    void setClaimID(const QString& claimID);

    QDate getDate() const;
    void setDate(const QDate& date);

    Invoice* getInvoice() const;
    void setInvoice(Invoice* invoice);

    ClaimResult* getResult() const;
    void setResult(ClaimResult* result);

private:
    QString         _source;
    QString         _claimID;
    QDate           _date;
    Invoice*        _invoice;
    ClaimResult*    _result;
};

#endif // CLAIM_H
