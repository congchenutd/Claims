#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryBase.h"

class Attachment;
class Provider;
class Invoice;
class Claim;
class ClaimResult;
class Deposit;

class Library: public LibraryBase
{
public:
    static Library* getInstance();

    Attachment*     getAttachment   (int id);
    Provider*       getProvider     (int id);
    Invoice*        getInvoice      (int id);
    Claim*          getClaim        (int id);
    ClaimResult*    getClaimResult  (int id);
    Deposit*        getDeposit      (int id);

private:
    Library();
};

#endif // LIBRARY_H
