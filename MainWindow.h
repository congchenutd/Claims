#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

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
    Ui::MainWindow ui;
};

#endif // MAINWINDOW_H
