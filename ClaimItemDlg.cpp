#include "ClaimElement.h"
#include "ClaimItemDlg.h"
#include "Constants.h"
#include <QComboBox>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMetaProperty>
#include <QSpinBox>

ClaimItemDlg::ClaimItemDlg(ClaimElement* element, QWidget* parent) :
    QDialog(parent),
    _element(element)
{
    _gridLayout = new QGridLayout(this);

    const QMetaObject* metaObj = element->metaObject();
    setWindowTitle(metaObj->className());

    int count = metaObj->propertyCount();
    int row = 0;
    for (int i = metaObj->propertyOffset(); i < count; ++i, ++row)
    {
        QMetaProperty property = metaObj->property(i);
        const char* propertyName = property.name();

        if (property.type() == QVariant::UserType)
            continue;

        _gridLayout->addWidget(new QLabel(QString(propertyName)), i, 0);
        QWidget* editor = createEditor(property);
        QByteArray editorUserPropertyName = editor->metaObject()->userProperty().name();
        QVariant value = element->property(propertyName);
        editor->setProperty(editorUserPropertyName, value);
        _gridLayout->addWidget(editor, i, 1);
    }

    _buttonBox = new QDialogButtonBox(this);
    _buttonBox->setOrientation(Qt::Horizontal);
    _buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
    connect(_buttonBox, SIGNAL(accepted()), SLOT(accept()));
    connect(_buttonBox, SIGNAL(rejected()), SLOT(reject()));
    _gridLayout->addWidget(_buttonBox, row + 1, 1, 1, 1);
}

QWidget* ClaimItemDlg::createEditor(const QMetaProperty& property) const
{
    if (property.isEnumType())
    {
        QComboBox* combo = new QComboBox;
        QMetaEnum enumerator = property.enumerator();
        for (int i = 0; i < enumerator.keyCount(); ++i)
            combo->insertItem(i, enumerator.key(i));
        return combo;
    }

    switch (property.type())
    {
    case QVariant::Int: {
        QSpinBox* spinBox = new QSpinBox;
        spinBox->setMinimum(INT_MIN);
        spinBox->setMaximum(INT_MAX);
        return spinBox;
    }
    case QVariant::Double: {
        QDoubleSpinBox* doubleSpinBox = new QDoubleSpinBox;
        doubleSpinBox->setMinimum(INT_MIN);
        doubleSpinBox->setMaximum(INT_MAX);
        return doubleSpinBox;
    }
    case QVariant::Date: {
        QDateEdit* dateEdit = new QDateEdit;
        dateEdit->setDisplayFormat(DATE_FORMAT);
        dateEdit->setDate(QDate::currentDate());
        dateEdit->setCalendarPopup(true);
        return dateEdit;
    }
    default:
        return new QLineEdit;
    }
}
