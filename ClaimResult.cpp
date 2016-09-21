#include "ClaimResult.h"

ClaimResult::ClaimResult(int id, const QDate& date, double paidAmount,
                         ResultState state, Claim* claim)
    : Attachable (id, 0),
      _date(date),
      _paidAmount(paidAmount),
      _state(state),
      _claim(claim)
{

}
