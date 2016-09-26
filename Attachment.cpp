#include "Attachment.h"
#include "AttachmentDAO.h"

Attachment::Attachment(const Attachment& another)
    : Persistable (another.getID(), another.getDAO())
{

}

Attachment& Attachment::operator = (const Attachment &another)
{
    return *this;
}

Attachment::Attachment(int id)
    : Persistable(id, AttachmentDAO::getInstance())
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
