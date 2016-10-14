#ifndef PROPERTYEDITORADAPTER_H
#define PROPERTYEDITORADAPTER_H

#include <QDateEdit>
#include <QLineEdit>
#include <QVariant>

/**
 * Provides a consistent interface for reading/writing QWidget value
 */
class PropertyEditorAdapter
{
public:
    PropertyEditorAdapter(QWidget* editor);
    virtual ~PropertyEditorAdapter();

    QWidget* getEditor() const;

    virtual QVariant getValue() const;
    virtual void setValue(const QVariant& value);

protected:
    QWidget* _editor;
};

class DateListEditAdapter: public PropertyEditorAdapter
{
public:
    DateListEditAdapter(QWidget* editor);

    QVariant getValue() const;
    void setValue(const QVariant& value);
};


#endif // PROPERTYEDITORADAPTER_H
