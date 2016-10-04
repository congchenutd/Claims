#include "ClaimItem.h"
#include "MainWindow.h"
#include "Invoice.h"
#include "ClaimItemDlg.h"
#include "Provider.h"
#include "Claim.h"
#include "ClaimResult.h"
#include "Deposit.h"
#include "Constants.h"
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);

    _scene = new QGraphicsScene(this);
    _scene->setSceneRect(0, 0, 1000, 500);

    ui.allClaimsView->setScene(_scene);
    ui.allClaimsView->setRenderHint(QPainter::Antialiasing);

//    ClaimItem* item = new ClaimItem;
//    scene->addItem(item);

//    Invoice* invoice = new Invoice(1);
//    invoice->setAmount(100);
//    invoice->setServiceDates(QVariantList()
//                             << QDate::fromString("2016-01-01", DATE_FORMAT)
//                             << QDate::fromString("2016-01-02", DATE_FORMAT));
//    invoice->setInvoiceDate(QDate::fromString("2016-01-08", DATE_FORMAT));
//    invoice->setState(Invoice::Deposited);
//    item->setClaimElement(invoice);

    connect(ui.actionAddProvider,       SIGNAL(triggered()), SLOT(onAddProvider()));
    connect(ui.actionAddInvoice,        SIGNAL(triggered()), SLOT(onAddInvoice()));
    connect(ui.actionAddClaim,          SIGNAL(triggered()), SLOT(onAddClaim()));
    connect(ui.actionAddClaimResult,    SIGNAL(triggered()), SLOT(onAddClaimResult()));
    connect(ui.actionAddDeposit,        SIGNAL(triggered()), SLOT(onAddDeposit()));
    connect(ui.actionAddAttachment,     SIGNAL(triggered()), SLOT(onAddAttachment()));
}

void MainWindow::onAddProvider()
{
    newItem(new Provider(-1));
}

void MainWindow::onAddInvoice()
{
    newItem(new Invoice(-1));
}

void MainWindow::onAddClaim()
{
    newItem(new Claim(-1));
}

void MainWindow::onAddClaimResult()
{
    newItem(new ClaimResult(-1));
}

void MainWindow::onAddDeposit()
{
    newItem(new Deposit(-1));
}

void MainWindow::onAddAttachment()
{
    newItem(new Attachment(-1));
}

void MainWindow::newItem(ClaimElement* element)
{
    ClaimItemDlg dlg(element, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        ClaimElement* element = dlg.getElement();

        ClaimItem* item = new ClaimItem;
        _scene->addItem(item);
        item->setClaimElement(element);
    }
}
