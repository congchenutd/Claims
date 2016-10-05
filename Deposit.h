#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class ClaimResult;

class Deposit: public Attachable
{
    Q_OBJECT
    Q_PROPERTY(QDate        Date        READ getDate        WRITE setDate)
    Q_PROPERTY(double       Amount      READ getAmount      WRITE setAmount)
    Q_PROPERTY(ClaimResult* ClaimResult READ getClaimResult WRITE setClaimResult)

public:
    Deposit(int id);

    QDate getDate() const;
    void setDate(const QDate& date);

    double getAmount() const;
    void setAmount(double amount);

    ClaimResult* getClaimResult();
    void setClaimResult(ClaimResult* result);

    QList<ClaimElement*> createSupportingElements() const;

private:
    QDate           _date;
    double          _amount;
    ClaimResult*    _result;
};

#endif // DEPOSIT_H
