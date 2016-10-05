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
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);

#ifdef Q_OS_OSX
    QDir::setCurrent(getCurrentPath());
#endif

    if (!openDB("Claims.db"))
        return 1;

	qRegisterMetaType<ClaimElement*>("ClaimElement*");
    qRegisterMetaType<Provider*>    ("Provider*");
    qRegisterMetaType<Invoice*>     ("Invoice*");
    qRegisterMetaType<Claim*>       ("Claim*");
    qRegisterMetaType<ClaimResult*> ("ClaimResult*");

	Library* library = Library::getInstance();
	LibraryDAO* libraryDAO = LibraryDAO::getInstance();

	MainWindow* wnd = MainWindow::getInstance();
	wnd->showMaximized();
    return app.exec();
}
