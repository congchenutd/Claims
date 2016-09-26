#include "Attachable.h"

Attachable::Attachable(int id, DAO* dao)
    : Persistable (id, dao) {}

Attachment* Attachable::getAttachment() const {
    return _attachment;
}

void Attachable::setAttachment(Attachment* attachment) {
    _attachment = attachment;
}
