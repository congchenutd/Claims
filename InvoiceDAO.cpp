#include "InvoiceDAO.h"
#include "Library.h"
#include "Provider.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>

InvoiceDAO::InvoiceDAO()
    : DAO("Invoice")
{
    addRelationships(Relationship("Invoice", "Provider"));
    createTable();
}

InvoiceDAO* InvoiceDAO::getInstance()
{
    static InvoiceDAO instance;
    return &instance;
}

Invoice* InvoiceDAO::load(int id) const
{
    QSqlQuery query;
    query.exec(tr("select ServiceDates, Date, Amount, State from %1 where id = %2")
                    .arg(getTableName())
                    .arg(id));
    if (query.next() == 0)
        return 0;

    QList<QDate>    serviceDates    = string2Dates(query.value(0).toString());
    Invoice::State  state           = string2State(query.value(3).toString());
    QDate           date            = query.value(1).toDate();
    double          amount          = query.value(2).toDouble();
    Invoice*        invoice         = new Invoice(id, serviceDates, date, amount, state);

    // Load relationships
    Library* library = Library::getInstance();
    query.exec(tr("select Provider.Name \
                   from Invoice, Provider, InvoiceProvider \
                   where Invoice.ID = %1 and Invoice.ID = InvoiceID and \
                   Provider.ID = ProviderID").arg(id));
    if (query.next() != 0)
        invoice->setProvider(library->getProvider(query.value(0).toString()));

    return invoice;
}

void InvoiceDAO::createTable()
{
    QSqlQuery query;
    query.exec(tr("create table %1 ( \
                    ID              int primary key, \
                    ServiceDates    varchar, \
                    Date            varchar, \
                    Amount          double,  \
                    State           varchar  \
                )").arg(getTableName()));

    createRelationshipTables();
}

void InvoiceDAO::removeRelationships(Persistable* persistable)
{
    Invoice* invoice = static_cast<Invoice*>(persistable);
    QSqlQuery query;
    query.exec(tr("delete from InvoiceProvider where InvoiceID = %1").arg(invoice->getID()));
}

void InvoiceDAO::insertRelationships(Persistable* persistable)
{
    Invoice* invoice = static_cast<Invoice*>(persistable);
    QSqlQuery query;

    if (invoice->getProvider() != 0)
        query.exec(tr("insert into InvoiceProvider values (%1, %2)")
                       .arg(invoice->getID())
                       .arg(invoice->getProvider()->getID()));
}

void InvoiceDAO::update(Persistable* persistable)
{
    Invoice* invoice = static_cast<Invoice*>(persistable);
    QSqlQuery query;
    query.exec(tr("update %1 set ServiceDates = \"%2\", Date = \"%3\", Amount = %4, State = \"%5\" where ID = %6")
                    .arg(getTableName())
                    .arg(dates2String(invoice->getServiceDates()))
                    .arg(invoice->getInvoiceDate().toString("yyyy-MM-dd"))
                    .arg(invoice->getAmount())
                    .arg(state2String(invoice->getState()))
                    .arg(invoice->getID())
               );

    updateRelationships(invoice);
}

void InvoiceDAO::insert(Persistable* persistable)
{
    Invoice* invoice = static_cast<Invoice*>(persistable);
    QSqlQuery query;
    query.exec(tr("insert into %1 values (%2, \"%3\", \"%4\", %5, \"%6\")")
                    .arg(getTableName())
                    .arg(invoice->getID())
                    .arg(dates2String(invoice->getServiceDates()))
                    .arg(invoice->getInvoiceDate().toString("yyyy-MM-dd"))
                    .arg(invoice->getAmount())
                    .arg(state2String(invoice->getState())));

    insertRelationships(invoice);
}


Invoice::State InvoiceDAO::string2State(const QString& string)
{
    if (string.toLower() == "undefined" || string.isEmpty())
        return Invoice::Undefined;
    if (string.toLower() == "unfiled")
        return Invoice::Unfiled;
    if (string.toLower() == "filed")
        return Invoice::Filed;
    if (string.toLower() == "paid")
        return Invoice::Paid;
    if (string.toLower() == "deposited")
        return Invoice::Deposited;
    return Invoice::Unfiled;
}

QString InvoiceDAO::state2String(Invoice::State state)
{
    switch (state)
    {
    case Invoice::Unfiled:
        return "Unfiled";
    case Invoice::Filed:
        return "Filed";
    case Invoice::Paid:
        return "Paid";
    case Invoice::Deposited:
        return "Deposited";
    default:
        return "Undefined";
    }
}

QList<QDate> InvoiceDAO::string2Dates(const QString& string)
{
    QStringList dates = string.split(";");
    QList<QDate> result;
    foreach(const QString& date, dates)
        result << QDate::fromString(date, "yyyy-MM-dd");
    return result;
}

QString InvoiceDAO::dates2String(const QList<QDate>& dates)
{
    QStringList dateList;
    foreach (const QDate& date, dates)
        dateList << date.toString("yyyy-MM-dd");
    return dateList.join(";");
}
