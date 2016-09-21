#ifndef PROVIDER_H
#define PROVIDER_H

#include "Persistable.h"

#include <QString>

class Provider: public Persistable
{
public:
    Provider(int id, const QString& name);

    QString getName() const;
    void setName(const QString& name);

private:
    QString _name;
};

#endif // PROVIDER_H
