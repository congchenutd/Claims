#include "ClaimItem.h"
#include "MainWindow.h"
#include "Invoice.h"
#include "ClaimItemDlg.h"
#include "Provider.h"
#include "Claim.h"
#include "ClaimResult.h"
#include "Deposit.h"
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1000, 500);

    ui.allClaimsView->setScene(scene);
    ui.allClaimsView->setRenderHint(QPainter::Antialiasing);

    ClaimItem* item = new ClaimItem;
    scene->addItem(item);

    Invoice* invoice = new Invoice(1);
    invoice->setAmount(100);
    invoice->setServiceDates("2016-01-01;2016-01-02");
    invoice->setInvoiceDate(QDate::fromString("2016-01-08", "yyyy-MM-dd"));
    invoice->setState(Invoice::Deposited);
    item->setClaimElement(invoice);

    connect(ui.actionAddProvider,       SIGNAL(triggered()), SLOT(onAddProvider()));
    connect(ui.actionAddInvoice,        SIGNAL(triggered()), SLOT(onAddInvoice()));
    connect(ui.actionAddClaim,          SIGNAL(triggered()), SLOT(onAddClaim()));
    connect(ui.actionAddClaimResult,    SIGNAL(triggered()), SLOT(onAddClaimResult()));
    connect(ui.actionAddDeposit,        SIGNAL(triggered()), SLOT(onAddDeposit()));
    connect(ui.actionAddAttachment,     SIGNAL(triggered()), SLOT(onAddAttachment()));
}

void MainWindow::onAddProvider()
{
    ClaimItemDlg dlg(new Provider(-1), this);
    dlg.exec();
}

void MainWindow::onAddInvoice()
{
    ClaimItemDlg dlg(new Invoice(-1), this);
    dlg.exec();
}

void MainWindow::onAddClaim()
{
    ClaimItemDlg dlg(new Claim(-1), this);
    dlg.exec();
}

void MainWindow::onAddClaimResult()
{
    ClaimItemDlg dlg(new ClaimResult(-1), this);
    dlg.exec();
}

void MainWindow::onAddDeposit()
{
    ClaimItemDlg dlg(new Deposit(-1), this);
    dlg.exec();
}

void MainWindow::onAddAttachment()
{
    ClaimItemDlg dlg(new Attachment(-1), this);
    dlg.exec();
}
