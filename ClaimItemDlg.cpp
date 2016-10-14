#include "ClaimElement.h"
#include "ClaimItemDlg.h"
#include "Constants.h"
#include "DateListLineEdit.h"
#include "FilePathLineEdit.h"
#include "PropertyEditorAdapter.h"
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
    loadFrom(element);
}

void ClaimItemDlg::accept()
{
    saveTo(_element);
    return QDialog::accept();
}

ClaimElement* ClaimItemDlg::getElement() const {
    return _element;
}

PropertyEditorAdapter* ClaimItemDlg::createEditor(ClaimElement* element, const QMetaProperty& property)
{
    if (property.isEnumType())
    {
        QComboBox* combo = new QComboBox;
        QMetaEnum enumerator = property.enumerator();
        for (int i = 0; i < enumerator.keyCount(); ++i)
            combo->insertItem(i, enumerator.key(i));
        return new PropertyEditorAdapter(combo);
    }

    if (QString(property.name()).contains("path", Qt::CaseInsensitive))
        return new PropertyEditorAdapter(new FilePathLineEdit(this));

    if (QString(property.name()).contains("dates", Qt::CaseInsensitive))
        return new DateListEditAdapter(new DateListLineEdit("yyyy-MM-dd", '_', LIST_SEPARATOR));

    switch (property.type())
    {
    case QVariant::Int: {
        QSpinBox* spinBox = new QSpinBox;
        spinBox->setMinimum(INT_MIN);
        spinBox->setMaximum(INT_MAX);
        return new PropertyEditorAdapter(spinBox);
    }

    case QVariant::Double: {
        QDoubleSpinBox* doubleSpinBox = new QDoubleSpinBox;
        doubleSpinBox->setMinimum(INT_MIN);
        doubleSpinBox->setMaximum(INT_MAX);
        return new PropertyEditorAdapter(doubleSpinBox);
    }

    case QVariant::Date: {
        QDateEdit* dateEdit = new QDateEdit;
        dateEdit->setDisplayFormat(DATE_FORMAT);
        dateEdit->setDate(QDate::currentDate());
        dateEdit->setCalendarPopup(true);
        return new PropertyEditorAdapter(dateEdit);
    }

    default:
        return new PropertyEditorAdapter(new QLineEdit);
    }
}

void ClaimItemDlg::loadFrom(ClaimElement* element)
{
    _gridLayout = new QGridLayout(this);
    const QMetaObject* metaObj = element->metaObject();
    setWindowTitle(metaObj->className());

    int row = 0;
    foreach (const QMetaProperty& property, element->getAllProperties())
    {
        const char* propertyName = property.name();
        _gridLayout->addWidget(new QLabel(QString(propertyName)), row, 0);
        PropertyEditorAdapter* editor = createEditor(element, property);
        QVariant value = element->property(propertyName);
        editor->setValue(value);
        _gridLayout->addWidget(editor->getEditor(), row++, 1);
        _editors.insert(QString(propertyName), editor);
    }

    _buttonBox = new QDialogButtonBox(this);
    _buttonBox->setOrientation(Qt::Horizontal);
    _buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
    connect(_buttonBox, SIGNAL(accepted()), SLOT(accept()));
    connect(_buttonBox, SIGNAL(rejected()), SLOT(reject()));
    _gridLayout->addWidget(_buttonBox, row + 1, 1, 1, 1);
}

void ClaimItemDlg::saveTo(ClaimElement* element)
{
    for (Editors::iterator it = _editors.begin(); it != _editors.end(); ++it)
    {
        QString                 propertyName    = it.key();
        PropertyEditorAdapter*  editor          = it.value();
        QVariant value = editor->getValue();
        element->setProperty(propertyName.toLatin1(), value);
    }
}
