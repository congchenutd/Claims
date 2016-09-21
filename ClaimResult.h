#ifndef CLAIMRESULT_H
#define CLAIMRESULT_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class Claim;

class ClaimResult: public Attachable
{
public:
    typedef enum {Paid, Rejected, Duplicate, Processing, Appealing} ResultState;

public:
    ClaimResult(int id, const QDate& date, double paidAmount, ResultState state, Claim* claim);

private:
    QDate       _date;
    double      _paidAmount;
    ResultState _state;
    Claim*      _claim;
};

#endif // CLAIMRESULT_H
