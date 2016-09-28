#include "ClaimElement.h"

ClaimElement::ClaimElement(int id, DAO* dao)
    : Persistable(id, dao)
{
}

QString ClaimElement::toHtml() const {
    return QString();
}
