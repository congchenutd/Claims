#include "Provider.h"
#include "ProviderDAO.h"

Provider::Provider(int id, const QString& name)
    : Persistable (id, ProviderDAO::getInstance()),
      _name(name)
{}

QString Provider::getName() const {
    return _name;
}

void Provider::setName(const QString& name) {
    _name = name;
}
