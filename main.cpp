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

	qRegisterMetaType<Provider*>("Provider*");

	Library* library = Library::getInstance();
	LibraryDAO* libraryDAO = LibraryDAO::getInstance();
//	libraryDAO->registerDAO(ProviderDAO::getInstance());
	libraryDAO->registerDAO(AttachmentDAO::getInstance());
	libraryDAO->registerDAO(InvoiceDAO::getInstance());

	Attachment* attachment = new Attachment(1);
	attachment->setTitle("Title");
	attachment->setPath("Path");
	library->addPersistable(attachment);

//	Provider* provider = new Provider(2);
//	provider->setName("Hello");
//	library->addPersistable(provider);

	Invoice* invoice = new Invoice(1);
	invoice->setAmount(100);
//	invoice->setProvider(provider);
	invoice->setAttachment(attachment);
	library->addPersistable(invoice);

	libraryDAO->save(library);

//	provider = (Provider*) ProviderDAO::getInstance()->load(2);
//	invoice  = (Invoice*)  InvoiceDAO ::getInstance()->load(1);

//	qDebug() << provider->getID() << invoice->getID();

    return 0;
}
