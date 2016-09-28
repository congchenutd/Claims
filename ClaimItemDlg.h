#ifndef CLAIMITEMDLG_H
#define CLAIMITEMDLG_H

#include <QDialog>

class ClaimElement;
class QDialogButtonBox;
class QGridLayout;

class ClaimItemDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimItemDlg(ClaimElement* element, QWidget* parent = 0);

private:
    ClaimElement*       _element;
    QDialogButtonBox*   _buttonBox;
    QGridLayout*        _gridLayout;
};

#endif // CLAIMITEMDLG_H
