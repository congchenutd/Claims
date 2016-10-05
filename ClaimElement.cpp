#include "ClaimElement.h"

ClaimElement::ClaimElement(int id, DAO* dao)
    : Persistable(id, dao)
{
}

QList<ClaimElement*> ClaimElement::createNextElements() const {
    return QList<ClaimElement*>();
}

QList<ClaimElement*> ClaimElement::createSupportingElements() const {
    return QList<ClaimElement*>();
}
