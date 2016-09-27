#include "Claim.h"
#include "ClaimResult.h"
#include "Deposit.h"
#include "Invoice.h"
#include "Library.h"
#include "Provider.h"

Library* Library::getInstance()
{
    static Library instance;
    return &instance;
}

Attachment* Library::getAttachment(int id) {
    return dynamic_cast<Attachment*>(getPersistable("Attachment", id));
}

Provider* Library::getProvider(int id) {
    return dynamic_cast<Provider*>(getPersistable("Provider", id));
}

Invoice* Library::getInvoice(int id) {
    return dynamic_cast<Invoice*>(getPersistable("Invoice", id));
}

Claim* Library::getClaim(int id) {
    return dynamic_cast<Claim*>(getPersistable("Claim", id));
}

ClaimResult* Library::getClaimResult(int id) {
    return dynamic_cast<ClaimResult*>(getPersistable("ClaimResult", id));
}

Deposit* Library::getDeposit(int id) {
    return dynamic_cast<Deposit*>(getPersistable("Deposit", id));
}

Library::Library() {}
