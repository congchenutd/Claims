#include "Attachable.h"

Attachable::Attachable(int id, DAO* dao)
    : Persistable (id, dao) {}

Attachable::~Attachable() {}

void Attachable::addAttachment(const Attachment& attachment) {
    _attachments << attachment;
}

QList<Attachment> Attachable::getAllAttachments() const {
    return _attachments;
}
