#include "ClaimElement.h"
#include "ClaimItemDlg.h"
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMetaProperty>

ClaimItemDlg::ClaimItemDlg(ClaimElement* element, QWidget* parent) :
    QDialog(parent),
    _element(element)
{
    _gridLayout = new QGridLayout(this);

    const QMetaObject* metaObj = element->metaObject();
    setWindowTitle(metaObj->className());

    int count = metaObj->propertyCount();
    int i = 0;
    for (; i < count; ++i)
    {
        const char* propertyName = metaObj->property(i).name();
        QVariant value = element->property(propertyName);

        if (QString(propertyName) == "objectName" || value.type() == QVariant::UserType)
            continue;

        _gridLayout->addWidget(new QLabel(QString(propertyName)), i, 0);
        _gridLayout->addWidget(new QLineEdit, i, 1);
    }

    _buttonBox = new QDialogButtonBox(this);
    _buttonBox->setOrientation(Qt::Horizontal);
    _buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
    connect(_buttonBox, SIGNAL(accepted()), SLOT(accept()));
    connect(_buttonBox, SIGNAL(rejected()), SLOT(reject()));
    _gridLayout->addWidget(_buttonBox, i, 1, 1, 1);
}
