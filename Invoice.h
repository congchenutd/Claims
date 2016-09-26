#ifndef INVOICE_H
#define INVOICE_H

#include "Attachable.h"
#include "Persistable.h"

#include <QDate>
#include <QString>

class Provider;

class Invoice: public Attachable
{
    Q_OBJECT
    Q_PROPERTY(QString      ServiceDates READ getServiceDates    WRITE setServiceDates)
    Q_PROPERTY(QDate        InvoiceDate  READ getInvoiceDate     WRITE setInvoiceDate)
    Q_PROPERTY(double       Amount       READ getAmount          WRITE setAmount)
    Q_PROPERTY(QString      State        READ getState           WRITE setState)
    Q_PROPERTY(Provider*    Provider     READ getProvider        WRITE setProvider)

public:
    Invoice(int id);

    QString getServiceDates() const;
    void setServiceDates(const QString& dates);

    QDate getInvoiceDate() const;
    void setInvoiceDate(const QDate& date);

    double getAmount() const;
    void setAmount(double amount);

    QString getState() const;
    void setState(const QString& state);

    Provider* getProvider() const;
    void setProvider(Provider* provider);

private:
    QList<QDate>    _serviceDates;
    QDate           _invoiceDate;
    double          _amount;
    QString         _note;
    QString         _state;
    Provider*       _provider;
};

#endif // INVOICE_H
