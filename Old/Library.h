#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMap>

class LibraryDAO;
class Provider;
class Invoice;

class Library
{
public:
    static Library* getInstance();

    void load();
    void save();

    void addProvider(Provider* provider);
    Provider* getProvider(const QString& name) const;
    QMap<QString, Provider*> getAllProviders() const;

    void addInvoice(Invoice* invoice);
    Invoice* getInvoice(int ID) const;
    QMap<int, Invoice*> getAllInvoices() const;

private:
    Library();
    ~Library();

private:
    LibraryDAO* _dao;

    QMap<QString, Provider*>    _providers;
    QMap<int, Invoice*>         _invoices;
};

#endif // LIBRARY_H
