#include "Attachment.h"
#include "AttachmentDAO.h"

Attachment::Attachment(int id)
    : ClaimElement(id, AttachmentDAO::getInstance())
{}

QString Attachment::getTitle() const {
    return _title;
}

void Attachment::setTitle(const QString& title) {
    _title = title;
}

QString Attachment::getPath() const {
    return _filePath;
}

void Attachment::setPath(const QString& path) {
    _filePath = path;
}
