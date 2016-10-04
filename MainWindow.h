#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class ClaimElement;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);

private slots:
    void onAddProvider();
    void onAddInvoice();
    void onAddClaim();
    void onAddClaimResult();
    void onAddDeposit();
    void onAddAttachment();

private:
    void newItem(ClaimElement* element);

private:
    Ui::MainWindow ui;
    QGraphicsScene* _scene;
};

#endif // MAINWINDOW_H
