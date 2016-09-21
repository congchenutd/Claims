#include "Library.h"
#include "LibraryDAO.h"
#include "Provider.h"
#include "Invoice.h"

Library* Library::getInstance()
{
    static Library instance;
    return &instance;
}

Library::Library() {
    _dao = LibraryDAO::getInstance();
}

Library::~Library() {
}

void Library::load() {
    _dao->load(this);
}

void Library::save() {
    _dao->save(this);
}

void Library::addProvider(Provider* provider) {
    _providers.insert(provider->getName(), provider);
}

Provider *Library::getProvider(const QString& name) const {
    return _providers.contains(name) ? _providers[name] : 0;
}

QMap<QString, Provider*> Library::getAllProviders() const {
    return _providers;
}

void Library::addInvoice(Invoice* invoice) {
    _invoices.insert(invoice->getID(), invoice);
}

Invoice *Library::getInvoice(int ID) const {
    return _invoices.contains(ID) ? _invoices[ID] : 0;
}

QMap<int, Invoice*> Library::getAllInvoices() const {
    return _invoices;
}
