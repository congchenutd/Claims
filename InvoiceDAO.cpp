#include "InvoiceDAO.h"
#include "LibraryBase.h"
#include "Provider.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>

InvoiceDAO::InvoiceDAO()
    : AttachableDAO("Invoice")
{
    addMapping("ServiceDates",  "SERVICEDATES", "varchar");
    addMapping("InvoiceDate",   "INVOICEDATES", "varchar");
    addMapping("Amount",        "AMOUNT",       "double");
    addMapping("State",         "STATE",        "varchar");
    addRelationships(Relationship("Invoice", "Provider"));
    createTable();
}

InvoiceDAO* InvoiceDAO::getInstance()
{
    static InvoiceDAO instance;
    return &instance;
}

Persistable* InvoiceDAO::createObject(int id) {
    return new Invoice(id);
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
