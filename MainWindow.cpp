#include "ClaimItem.h"
#include "MainWindow.h"
#include "Invoice.h"
#include "ClaimItemDlg.h"
#include "Provider.h"
#include "Claim.h"
#include "ClaimResult.h"
#include "Deposit.h"
#include "Constants.h"
#include "GraphicsScene.h"
#include "InvoiceDAO.h"
#include "ClaimDAO.h"
#include "ClaimResultDAO.h"
#include "DepositDAO.h"
#include "AttachmentDAO.h"
#include "GraphicsScene.h"
#include <QResizeEvent>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    ui.splitter->setSizes(QList<int>() << 200 << 100);

    _scene = new GraphicsScene(this);
    _scene->setSceneRect(0, 0, 1000, 1000);

    ui.allClaimsView->setScene(_scene);
    ui.allClaimsView->setRenderHint(QPainter::Antialiasing);
    ui.allClaimsView->setDragMode(QGraphicsView::ScrollHandDrag);

    connect(ui.actionAddProvider,       SIGNAL(triggered()), SLOT(onAddProvider()));
    connect(ui.actionAddInvoice,        SIGNAL(triggered()), SLOT(onAddInvoice()));
    connect(ui.actionAddClaim,          SIGNAL(triggered()), SLOT(onAddClaim()));
    connect(ui.actionAddClaimResult,    SIGNAL(triggered()), SLOT(onAddClaimResult()));
    connect(ui.actionAddDeposit,        SIGNAL(triggered()), SLOT(onAddDeposit()));
    connect(ui.actionAddAttachment,     SIGNAL(triggered()), SLOT(onAddAttachment()));
    connect(ui.actionZoomToFit,         SIGNAL(triggered()), SLOT(onZoomToFit()));
    connect(ui.actionZoomIn,            SIGNAL(triggered()), SLOT(onZoomIn()));
    connect(ui.actionZoomOut,           SIGNAL(triggered()), SLOT(onZoomOut()));
}

MainWindow* MainWindow::_instance = 0;

MainWindow* MainWindow::getInstance()
{
    if (_instance == 0)
        _instance = new MainWindow;
    return _instance;
}

void MainWindow::onAddProvider()
{
    newItem(new Provider(-1));
}

void MainWindow::onAddInvoice()
{
    newItem(new Invoice(InvoiceDAO::getInstance()->getNextID()));
}

void MainWindow::onAddClaim()
{
    newItem(new Claim(ClaimDAO::getInstance()->getNextID()));
}

void MainWindow::onAddClaimResult()
{
    newItem(new ClaimResult(ClaimResultDAO::getInstance()->getNextID()));
}

void MainWindow::onAddDeposit()
{
    newItem(new Deposit(DepositDAO::getInstance()->getNextID()));
}

void MainWindow::onAddAttachment()
{
    newItem(new Attachment(AttachmentDAO::getInstance()->getNextID()));
}

void MainWindow::onZoomIn()
{
    ui.allClaimsView->scale(1.2, 1.2);
}

void MainWindow::onZoomOut()
{
    ui.allClaimsView->scale(0.8, 0.8);
}

void MainWindow::onZoomToFit() {
    ui.allClaimsView->fitInView(_scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::onZoomReset()
{

}

void MainWindow::onAddNextElement()
{
    QAction* action = static_cast<QAction*>(sender());
    ClaimElement* nextElement = action->data().value<ClaimElement*>();

    ClaimItemDlg dlg(nextElement);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (ClaimItem* item = _scene->getSelectedItem())
        {
            ClaimItem* nextItem = new ClaimItem;
            nextItem->setElement(nextElement);
            _scene->addItem(nextItem);
            item->setNextItem(nextItem);
            _scene->connectItems(item, nextItem);
        }
    }
}

void MainWindow::onAddSupportingElement()
{
    QAction* action = static_cast<QAction*>(sender());
    ClaimElement* supportingElement = action->data().value<ClaimElement*>();

    ClaimItemDlg dlg(supportingElement);
    if (dlg.exec() == QDialog::Accepted)
    {

    }
}

void MainWindow::onEditItem()
{
    QAction* action = static_cast<QAction*>(sender());
    ClaimElement* element = action->data().value<ClaimElement*>();

    ClaimItemDlg dlg(element);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (ClaimItem* item = _scene->getSelectedItem())
            item->setElement(element);
    }
}

void MainWindow::newItem(ClaimElement* element)
{
    ClaimItemDlg dlg(element, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        ClaimElement* element = dlg.getElement();

        ClaimItem* item = new ClaimItem;
        _scene->addItem(item);
        item->setElement(element);
    }
}
