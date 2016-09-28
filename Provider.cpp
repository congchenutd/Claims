#include "Provider.h"
#include "ProviderDAO.h"

Provider::Provider(int id)
    : ClaimElement (id, ProviderDAO::getInstance())
{}

QString Provider::getName() const {
    return _name;
}

void Provider::setName(const QString& name) {
    _name = name;
}

QString Provider::toHtml() const {
    return tr("<H3>Provider</H3><P>%1</P>").arg(getName());
}
