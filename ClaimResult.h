#ifndef CLAIMRESULT_H
#define CLAIMRESULT_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class Claim;

class ClaimResult: public Attachable
{
    Q_OBJECT
    Q_PROPERTY(QDate    Date        READ getDate        WRITE setDate)
    Q_PROPERTY(double   PaidAmount  READ getPaidAmount  WRITE setPaidAmount)
    Q_PROPERTY(QString  State       READ getState       WRITE setState)
    Q_PROPERTY(Claim*   Claim       READ getClaim       WRITE setClaim)

public:
    typedef enum {Paid, Rejected, Duplicate, Processing, Appealing} State;

public:
    ClaimResult(int id);

    QDate getDate() const;
    void setDate(const QDate& date);

    double getPaidAmount() const;
    void setPaidAmount(double amount);

    QString getState() const;
    void setState(const QString& state);

    Claim* getClaim() const;
    void setClaim(Claim* claim);

private:
    QDate   _date;
    double  _paidAmount;
    QString _state;
    Claim*  _claim;
};

#endif // CLAIMRESULT_H
