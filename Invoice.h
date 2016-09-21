#ifndef INVOICE_H
#define INVOICE_H

#include "Attachable.h"
#include "Persistable.h"

#include <QDate>
#include <QString>

class Provider;

class Invoice: public Attachable
{
public:
    typedef enum {Undefined, Unfiled, Filed, Paid, Deposited} State;

public:
    Invoice(int id, const QList<QDate>& serviceDates, const QDate& date, double amount, State state);

    Provider* getProvider() const;
    void setProvider(Provider* provider);

    QList<QDate> getServiceDates() const;
    void setServiceDates(const QList<QDate>& dates);

    QDate getInvoiceDate() const;
    void setInvoiceDate(const QDate& date);

    double getAmount() const;
    void setAmount(double amount);

    State getState() const;
    void setState(State state);

public:
    static State    string2State(const QString& state);
    static QString  state2String(State state);

private:
    QList<QDate>    _serviceDates;
    QDate           _invoiceDate;
    double          _amount;
    QString         _note;
    State    _state;
    Provider*       _provider;
};

#endif // INVOICE_H
