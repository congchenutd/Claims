#ifndef PROVIDER_H
#define PROVIDER_H

#include "ClaimElement.h"

#include <QString>

class Provider: public ClaimElement
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ getName WRITE setName)

public:
    Provider(int id);

    QString getName() const;
    void setName(const QString& name);

    QString toHtml() const;

private:
    QString _name;
};

#endif // PROVIDER_H
