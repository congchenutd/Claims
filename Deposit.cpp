#include "Deposit.h"

Deposit::Deposit(int id, const QDate& date, double amount)
    : Attachable(id, 0),
      _date(date),
      _amount(amount)
{

}
