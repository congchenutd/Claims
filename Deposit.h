#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Attachable.h"

#include <QDate>
#include <QString>

class Deposit: public Attachable
{
public:
    Deposit(int id, const QDate& date, double amount);

private:
    QDate   _date;
    double  _amount;
};

#endif // DEPOSIT_H
