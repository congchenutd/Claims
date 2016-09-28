#include "Invoice.h"
#include "InvoiceDAO.h"

Invoice::Invoice(int id)
    : Attachable(id, InvoiceDAO::getInstance()),
      _provider(0)
{}

Provider* Invoice::getProvider() const {
    return _provider;
}

void Invoice::setProvider(Provider* provider) {
    _provider = provider;
}

QString Invoice::toHtml() const
{
    return tr("<H2>Invoice</H2>\
               <P>Service dates: %1<br>\
                   Invoice date: %2<br>\
                   Amount: %3<br>\
                   State: %4\
               </P>")
              .arg(getServiceDates()).arg(getInvoiceDate().toString("yyyy-MM-dd")).arg(getAmount()).arg(getState());
}

QString Invoice::getServiceDates() const
{
    QStringList dates;
    foreach (const QDate& date, _serviceDates)
        dates << date.toString("yyyy-MM-dd");
    return dates.join(";");
}

void Invoice::setServiceDates(const QString& dates)
{
    _serviceDates.clear();
    QStringList dateList = dates.split(";");
    foreach (const QString& date, dateList)
        _serviceDates << QDate::fromString(date, "yyyy-MM-dd");
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
