#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class ClaimElement;
class GraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);

    static MainWindow* getInstance();

private slots:
    void onAddProvider();
    void onAddInvoice();
    void onAddClaim();
    void onAddClaimResult();
    void onAddDeposit();
    void onAddAttachment();
    void onZoomIn();
    void onZoomOut();
    void onZoomToFit();
    void onZoomReset();

    void onAddNextElement();
    void onAddSupportingElement();
    void onEditItem();

private:
    void newItem(ClaimElement* element);

private:
    Ui::MainWindow ui;
    GraphicsScene* _scene;
    static MainWindow* _instance;
};

#endif // MAINWINDOW_H
