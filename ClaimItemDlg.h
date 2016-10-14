#ifndef CLAIMITEMDLG_H
#define CLAIMITEMDLG_H

#include <QDialog>
#include <QMap>

class ClaimElement;
class QDialogButtonBox;
class QGridLayout;
class QWidget;
class PropertyEditorAdapter;

class ClaimItemDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimItemDlg(ClaimElement* element, QWidget* parent = 0);
    void accept();
    ClaimElement* getElement() const;

private:
    PropertyEditorAdapter* createEditor(ClaimElement* element, const QMetaProperty& property);
    void loadFrom(ClaimElement* element);
    void saveTo  (ClaimElement* element);

private:
    typedef QMap<QString, PropertyEditorAdapter*> Editors;
    ClaimElement*       _element;
    QDialogButtonBox*   _buttonBox;
    QGridLayout*        _gridLayout;
    Editors             _editors;
};

#endif // CLAIMITEMDLG_H
