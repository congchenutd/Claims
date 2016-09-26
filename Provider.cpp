#include "Provider.h"
#include "ProviderDAO.h"

Provider::Provider(int id)
    : Persistable (id, ProviderDAO::getInstance())
{}

QString Provider::getName() const {
    return _name;
}

void Provider::setName(const QString& name) {
    _name = name;
}
