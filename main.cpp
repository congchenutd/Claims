#include "MainWindow.h"
#include "Attachment.h"
#include "Claim.h"
#include "ClaimResult.h"
#include "Deposit.h"
#include "Invoice.h"
#include "Provider.h"
#include "Library.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QDir>
#include <QSqlQuery>

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

    //    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    Library* library = Library::getInstance();
//    library->load();
    Provider* ALLS = new Provider(1, "ALLS");
    Invoice* invoice = new Invoice(1, QList<QDate>() << QDate::fromString("2016-01-01", "yyyy-MM-dd")
                                                     << QDate::fromString("2016-01-08", "yyyy-MM-dd"),
                                   QDate::fromString("2016-01-09", "yyyy-MM-dd"),
                                   100,
                                   Invoice::Unfiled);
    invoice->setProvider(ALLS);
    library->addProvider(ALLS);
    library->addInvoice(invoice);
    library->save();

//    QList<QDate> dates;
//    dates << QDate::fromString("2016-01-01", "yyyy-MM-dd") << QDate::fromString("2016-01-08", "yyyy-MM-dd");
//    QDate date = QDate::fromString("2016-01-08", "yyyy-MM-dd");
//    Invoice* invoice1 = new Invoice(1, ALLS, dates, date, 100);
//    Claim* claim1 = new Claim("1", QDate::fromString("2016-01-08", "yyyy-MM-dd"), invoice1);
//    ClaimResult* result1 = new ClaimResult("1", QDate::fromString("2016-01-15", "yyyy-MM-dd"), 80, ClaimResult::Paid, claim1);
//    Attachment claimDoc("1", "claim", "");
//    Attachment invoiceDoc("2", "invoice", "");
//    Attachment eob("3", "eob", "");
//    invoice1->addAttachment(invoiceDoc);
//    claim1->addAttachment(claimDoc);
//    result1->addAttachment(eob);

    return 0;
}
