#include "Invoice.h"
#include "Library.h"
#include "Provider.h"

Library* Library::getInstance()
{
    static Library instance;
    return &instance;
}

Provider* Library::getProvider(int id) {
    return dynamic_cast<Provider*>(getPersistable("Provider", id));
}

Invoice* Library::getInvoice(int id) {
    return dynamic_cast<Invoice*>(getPersistable("Invoice", id));
}

Library::Library() {}
