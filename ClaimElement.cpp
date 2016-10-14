#include "ClaimElement.h"

ClaimElement::ClaimElement(int id, DAO* dao)
    : Persistable(id, dao)
{
}

ClaimElement* ClaimElement::createNextElement() const {
    return 0;
}

QList<ClaimElement*> ClaimElement::createSupportingElements() const {
    return QList<ClaimElement*>();
}

ClaimElement* ClaimElement::getNext() const {
    return _next;
}

void ClaimElement::setNext(ClaimElement* next) {
    _next = next;
}
