#include "Claim.h"
#include "Invoice.h"
#include "InvoiceDAO.h"
#include "ClaimDAO.h"
#include "Provider.h"
#include "Attachment.h"
#include "ProviderDAO.h"
#include "AttachmentDAO.h"

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

QString Invoice::getServiceDates() const {
    return _serviceDates;
}

void Invoice::setServiceDates(const QString &dates) {
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

ClaimElement* Invoice::createNextElement() const {
    return new Claim(ClaimDAO::getInstance()->getNextID());
}

QList<ClaimElement*> Invoice::createSupportingElements() const {
    return QList<ClaimElement*>() << new Provider  (ProviderDAO ::getInstance()->getNextID())
                                  << new Attachment(AttachmentDAO::getInstance()->getNextID());
}
