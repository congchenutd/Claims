#ifndef CLAIMITEMDLG_H
#define CLAIMITEMDLG_H

#include <QDialog>
#include <QMap>

class ClaimElement;
class QDialogButtonBox;
class QGridLayout;
class QWidget;

class ClaimItemDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimItemDlg(ClaimElement* element, QWidget* parent = 0);

private:
    QWidget* createEditor(const QMetaProperty& property) const;

private:
    ClaimElement*           _element;
    QDialogButtonBox*       _buttonBox;
    QGridLayout*            _gridLayout;
    QMap<QString, QWidget*> _editors;
};

#endif // CLAIMITEMDLG_H
