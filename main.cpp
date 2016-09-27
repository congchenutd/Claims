#include "MainWindow.h"
#include "Attachment.h"
#include "Claim.h"
#include "ClaimResult.h"
#include "Deposit.h"
#include "Invoice.h"
#include "Provider.h"
#include "Library.h"
#include "DAO.h"
#include "LibraryDAO.h"
#include "ProviderDAO.h"
#include "InvoiceDAO.h"
#include "AttachmentDAO.h"
#include "Attachment.h"
#include "ClaimDAO.h"
#include "ClaimResultDAO.h"
#include "DepositDAO.h"
#include "Deposit.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QDir>
#include <QSqlQuery>
#include <QDebug>

// workaround for a bug on mac > Mavericks
// Finder returns / as the working path of an app bundle
// but if the app is run from terminal, the path is correct
// This method calcluates the path of the bundle from the application's path
QString getCurrentPath()
{
    QDir dir(QApplication::applicationDirPath());
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    return dir.absolutePath();
}

bool openDB(const QString& name)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(name);
    if(!database.open())
    {
        QMessageBox::critical(0, "Error", database.lastError().text());
        return false;
    }

    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON");
    return true;
}

int main(int argc, char *argv[])
{
//	QApplication app(argc, argv);
//	app.setAttribute(Qt::AA_UseHighDpiPixmaps);

//#ifdef Q_OS_OSX
//    QDir::setCurrent(getCurrentPath());
//#endif

    if (!openDB("Claims.db"))
        return 1;

    qRegisterMetaType<Provider*>    ("Provider*");
    qRegisterMetaType<Invoice*>     ("Invoice*");
    qRegisterMetaType<Claim*>       ("Claim*");
    qRegisterMetaType<ClaimResult*> ("ClaimResult*");

	Library* library = Library::getInstance();
	LibraryDAO* libraryDAO = LibraryDAO::getInstance();
    libraryDAO->registerDAO(ProviderDAO     ::getInstance());
    libraryDAO->registerDAO(AttachmentDAO   ::getInstance());
    libraryDAO->registerDAO(InvoiceDAO      ::getInstance());
    libraryDAO->registerDAO(ClaimResultDAO  ::getInstance());
    libraryDAO->registerDAO(DepositDAO      ::getInstance());
    libraryDAO->registerDAO(ClaimDAO        ::getInstance());

//    Attachment* attachment = new Attachment(1);
//    attachment->setTitle("Title");
//    attachment->setPath("Path");
//    library->addPersistable(attachment);

//    Provider* provider = new Provider(2);
//    provider->setName("Hello");
//    library->addPersistable(provider);

//    Invoice* invoice = new Invoice(3);
//    invoice->setAmount(100);
//    invoice->setServiceDates("2016-01-01;2016-01-08");
//    invoice->setInvoiceDate(QDate::fromString("2016-01-09", "yyyy-MM-dd"));
//    invoice->setProvider(provider);
//    invoice->setAttachment(attachment);
//    library->addPersistable(invoice);

//    ClaimResult* result = new ClaimResult(5);
//    result->setDate(QDate::fromString("2016-01-30", "yyyy-MM-dd"));
//    result->setPaidAmount(80);
//    result->setState("Paid");
//    result->setAttachment(attachment);
//    library->addPersistable(result);

//    Claim* claim = new Claim(4);
//    claim->setClaimee("BlueShield");
//    claim->setClaimID("ASDFASDFASDF");
//    claim->setDate(QDate::fromString("2016-01-20", "yyyy-MM-dd"));
//    claim->setInvoice(invoice);
//    claim->setClaimResult(result);
//    claim->setAttachment(attachment);
//    library->addPersistable(claim);

//    Deposit* deposit = new Deposit(6);
//    deposit->setDate(QDate::fromString("2016-02-01", "yyyy-MM-dd"));
//    deposit->setAmount(80);
//    deposit->setClaimResult(result);
//    deposit->setAttachment(attachment);
//    library->addPersistable(deposit);

//	libraryDAO->save(library);

//    attachment  = (Attachment*)     AttachmentDAO   ::getInstance()->load(1);
//    provider    = (Provider*)       ProviderDAO     ::getInstance()->load(2);
//    invoice     = (Invoice*)        InvoiceDAO      ::getInstance()->load(3);
//    claim       = (Claim*)          ClaimDAO        ::getInstance()->load(4);
//    result      = (ClaimResult*)    ClaimResultDAO  ::getInstance()->load(5);
//    deposit     = (Deposit*)        DepositDAO      ::getInstance()->load(6);

//    qDebug() << attachment->getID()
//             << provider->getID()
//             << invoice->getID()
//             << claim->getID()
//             << result->getID()
//             << deposit->getID();

    libraryDAO->load(library);

    return 0;
}
