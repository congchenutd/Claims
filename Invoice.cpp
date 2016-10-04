#include "Invoice.h"
#include "InvoiceDAO.h"

Invoice::Invoice(int id)
    : Attachable(id, InvoiceDAO::getInstance()),
      _amount(0),
      _state(Unfiled),
      _provider(0)
{}

Provider* Invoice::getProvider() const {
    return _provider;
}

void Invoice::setProvider(Provider* provider) {
    _provider = provider;
}

QVariantList Invoice::getServiceDates() const {
    return _serviceDates;
}

void Invoice::setServiceDates(const QVariantList& dates) {
    _serviceDates = dates;
}

QDate Invoice::getInvoiceDate() const {
    return _invoiceDate;
}

void Invoice::setInvoiceDate(const QDate& date) {
    _invoiceDate = date;
}

double Invoice::getAmount() const {
    return _amount;
}

void Invoice::setAmount(double amount) {
    _amount = amount;
}

Invoice::State Invoice::getState() const {
    return _state;
}

void Invoice::setState(const State& state) {
    _state = state;
}
