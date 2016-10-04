#ifndef INVOICE_H
#define INVOICE_H

#include "Attachable.h"
#include "Persistable.h"

#include <QDate>
#include <QString>
#include <QVariantList>

class Provider;

class Invoice: public Attachable
{
public:
    enum State {Unfiled, Filed, Paid, Deposited};
    Q_ENUMS(State)

    Q_OBJECT
    Q_PROPERTY(QVariantList ServiceDates    READ getServiceDates    WRITE setServiceDates)
    Q_PROPERTY(QDate        InvoiceDate     READ getInvoiceDate     WRITE setInvoiceDate)
    Q_PROPERTY(double       Amount          READ getAmount          WRITE setAmount)
    Q_PROPERTY(State        State           READ getState           WRITE setState)
    Q_PROPERTY(Provider*    Provider        READ getProvider        WRITE setProvider)

public:
    Invoice(int id);

    QVariantList getServiceDates() const;
    void setServiceDates(const QVariantList& dates);

    QDate getInvoiceDate() const;
    void setInvoiceDate(const QDate& date);

    double getAmount() const;
    void setAmount(double amount);

    State getState() const;
    void setState(const State& state);

    Provider* getProvider() const;
    void setProvider(Provider* provider);

private:
    QVariantList    _serviceDates;
    QDate           _invoiceDate;
    double          _amount;
    QString         _note;
    State           _state;
    Provider*       _provider;
};

#endif // INVOICE_H
