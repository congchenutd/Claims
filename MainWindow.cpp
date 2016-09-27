#include "ClaimItem.h"
#include "MainWindow.h"
#include "Invoice.h"
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

}

void MainWindow::onAddInvoice()
{

}

void MainWindow::onAddClaim()
{

}

void MainWindow::onAddClaimResult()
{

}

void MainWindow::onAddDeposit()
{

}

void MainWindow::onAddAttachment()
{

}
