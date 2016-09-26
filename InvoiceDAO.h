#ifndef INVOICEDAO_H
#define INVOICEDAO_H

#include "AttachableDAO.h"
#include "Invoice.h"

class InvoiceDAO: public AttachableDAO
{
public:
    static InvoiceDAO* getInstance();

protected:
    Persistable* createObject(int id);

private:
    static Invoice::State  string2State(const QString& string);
    static QString         state2String(Invoice::State state);
    static QList<QDate>    string2Dates(const QString& string);
    static QString         dates2String(const QList<QDate>& dates);

private:
    InvoiceDAO();
};

#endif // INVOICEDAO_H
