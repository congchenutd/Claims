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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);

    _scene = new GraphicsScene(this);
    _scene->setSceneRect(0, 0, 1000, 500);

    ui.allClaimsView->setScene(_scene);
    ui.allClaimsView->setRenderHint(QPainter::Antialiasing);

    connect(ui.actionAddProvider,       SIGNAL(triggered()), SLOT(onAddProvider()));
    connect(ui.actionAddInvoice,        SIGNAL(triggered()), SLOT(onAddInvoice()));
    connect(ui.actionAddClaim,          SIGNAL(triggered()), SLOT(onAddClaim()));
    connect(ui.actionAddClaimResult,    SIGNAL(triggered()), SLOT(onAddClaimResult()));
    connect(ui.actionAddDeposit,        SIGNAL(triggered()), SLOT(onAddDeposit()));
    connect(ui.actionAddAttachment,     SIGNAL(triggered()), SLOT(onAddAttachment()));

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

void MainWindow::onAddNextElement()
{
    QAction* action = static_cast<QAction*>(sender());
    ClaimElement* nextElement = action->data().value<ClaimElement*>();

    ClaimItemDlg dlg(nextElement);
    if (dlg.exec() == QDialog::Accepted)
    {
        ClaimItem* item = new ClaimItem;
        item->setClaimElement(nextElement);
        _scene->addItem(item);
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
