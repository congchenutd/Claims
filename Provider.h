#ifndef PROVIDER_H
#define PROVIDER_H

#include "Persistable.h"

#include <QString>

class Provider: public Persistable
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ getName WRITE setName)

public:
    Provider(int id);

    QString getName() const;
    void setName(const QString& name);

private:
    QString _name;
};

#endif // PROVIDER_H
