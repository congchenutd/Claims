#ifndef INVOICEDAO_H
#define INVOICEDAO_H

#include "DAO.h"
#include "Invoice.h"

class InvoiceDAO: public DAO
{
public:
    static InvoiceDAO* getInstance();

    Invoice* load(int id) const;

protected:
    void createTable();
    void removeRelationships(Persistable* persistable);
    void insertRelationships(Persistable* persistable);

private:
    static Invoice::State  string2State(const QString& string);
    static QString         state2String(Invoice::State state);
    static QList<QDate>    string2Dates(const QString& string);
    static QString         dates2String(const QList<QDate>& dates);

private:
    InvoiceDAO();
    ~InvoiceDAO() {}
    void update(Persistable* persistable);
    void insert(Persistable* persistable);
};

#endif // INVOICEDAO_H
