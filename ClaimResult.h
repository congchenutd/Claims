#ifndef CLAIMRESULT_H
#define CLAIMRESULT_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class Claim;

class ClaimResult: public Attachable
{
public:
    enum State {Paid, Rejected, Duplicate, Processing, Appealing};
    Q_ENUMS(State)

    Q_OBJECT
    Q_PROPERTY(QDate    Date        READ getDate        WRITE setDate)
    Q_PROPERTY(double   PaidAmount  READ getPaidAmount  WRITE setPaidAmount)
    Q_PROPERTY(State    State       READ getState       WRITE setState)
    Q_PROPERTY(Claim*   Claim       READ getClaim       WRITE setClaim)

public:
    ClaimResult(int id);

    QDate getDate() const;
    void setDate(const QDate& date);

    double getPaidAmount() const;
    void setPaidAmount(double amount);

    State getState() const;
    void setState(State state);

    Claim* getClaim() const;
    void setClaim(Claim* claim);

    QString getDisplayName() const;

private:
    QDate   _date;
    double  _paidAmount;
    State   _state;
    Claim*  _claim;
};

#endif // CLAIMRESULT_H
