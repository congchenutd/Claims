#include "LibraryDAO.h"
#include "Library.h"
#include "ProviderDAO.h"
#include "InvoiceDAO.h"

#include <QDir>
#include <QSqlQuery>
#include <QVariant>

LibraryDAO* LibraryDAO::getInstance()
{
    static LibraryDAO instance;
    return &instance;
}

void LibraryDAO::load(Library* library)
{
    QSqlQuery query;

    query.exec("select ID from Provider Order By ID");
    while (query.next())
        library->addProvider(ProviderDAO::getInstance()->load(query.value(0).toInt()));

    query.exec("select ID from Invoice Order By ID");
    while (query.next())
        library->addInvoice(InvoiceDAO::getInstance()->load(query.value(0).toInt()));
}

void LibraryDAO::save(Library* library)
{
    if (QSqlDatabase::database().transaction())
    {
        foreach (Provider* provider, library->getAllProviders())
            provider->save();

        foreach (Invoice* invoice, library->getAllInvoices())
            invoice->save();

        QSqlDatabase::database().commit();
    }
}

LibraryDAO::LibraryDAO() {
}

LibraryDAO::~LibraryDAO() {}
