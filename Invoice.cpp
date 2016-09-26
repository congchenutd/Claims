#include "Invoice.h"
#include "InvoiceDAO.h"

Invoice::Invoice(int id)
    : Attachable(id, InvoiceDAO::getInstance())
{}

Provider* Invoice::getProvider() const {
    return _provider;
}

void Invoice::setProvider(Provider* provider) {
    _provider = provider;
}

QList<QDate> Invoice::getServiceDates() const {
    return _serviceDates;
}

void Invoice::setServiceDates(const QList<QDate>& dates) {
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

QString Invoice::getState() const {
    return _state;
}

void Invoice::setState(const QString& state) {
    _state = state;
}
