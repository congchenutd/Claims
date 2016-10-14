#ifndef CLAIM_H
#define CLAIM_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class Invoice;
class ClaimResult;

class Claim: public Attachable
{
    Q_OBJECT
    Q_PROPERTY(QString      Claimee      READ getClaimee     WRITE setClaimee)
    Q_PROPERTY(QString      ClaimID      READ getClaimID     WRITE setClaimID)
    Q_PROPERTY(QDate        Date         READ getDate        WRITE setDate)
    Q_PROPERTY(Invoice*     Invoice      READ getInvoice     WRITE setInvoice)
    Q_PROPERTY(ClaimResult* ClaimResult  READ getClaimResult WRITE setClaimResult)

public:
    Claim(int id);

    QString getClaimee() const;
    void setClaimee(const QString& source);

    QString getClaimID() const;
    void setClaimID(const QString& claimID);

    QDate getDate() const;
    void setDate(const QDate& date);

    Invoice* getInvoice() const;
    void setInvoice(Invoice* invoice);

    ClaimResult* getClaimResult() const;
    void setClaimResult(ClaimResult* result);

    ClaimElement* createNextElement() const;
    QList<ClaimElement*> createSupportingElements() const;

private:
    QString         _claimee;
    QString         _claimID;
    QDate           _date;
    Invoice*        _invoice;
    ClaimResult*    _result;
};

#endif // CLAIM_H
