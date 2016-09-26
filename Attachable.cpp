#include "Attachable.h"

Attachable::Attachable(int id, DAO* dao)
    : Persistable (id, dao),
      _attachment(0)
{}

Attachment* Attachable::getAttachment() const {
    return _attachment;
}

void Attachable::setAttachment(Attachment* attachment) {
    _attachment = attachment;
}
