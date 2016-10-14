#include "PropertyEditorAdapter.h"
#include "DateListLineEdit.h"
#include "Constants.h"
#include <QMetaProperty>

PropertyEditorAdapter::PropertyEditorAdapter(QWidget* editor)
    : _editor (editor)
{}

PropertyEditorAdapter::~PropertyEditorAdapter() {}

QWidget* PropertyEditorAdapter::getEditor() const {
    return _editor;
}

QVariant PropertyEditorAdapter::getValue() const
{
    QByteArray editorUserPropertyName = _editor->metaObject()->userProperty().name();
    return _editor->property(editorUserPropertyName);
}

void PropertyEditorAdapter::setValue(const QVariant& value)
{
    QByteArray editorUserPropertyName = _editor->metaObject()->userProperty().name();
    _editor->setProperty(editorUserPropertyName, value);
}

/////////////////////////////////////////////////////////////////////////////////////
DateListEditAdapter::DateListEditAdapter(QWidget* editor)
    : PropertyEditorAdapter (editor)
{}

QVariant DateListEditAdapter::getValue() const {
    return static_cast<DateListLineEdit*>(_editor)->text();
}

void DateListEditAdapter::setValue(const QVariant& value) {
    static_cast<DateListLineEdit*>(_editor)->setText(value.toString());
}
