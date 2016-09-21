#include "Attachment.h"
#include "AttachmentDAO.h"

Attachment::Attachment(int id, const QString& title, const QString& filePath)
    : Persistable(id, AttachmentDAO::getInstance()),
      _title(title),
      _filePath(filePath)
{

}

QString Attachment::getTitle() const {
    return _title;
}

void Attachment::setTitle(const QString& title) {
    _title = title;
}

QString Attachment::getFilePath() const {
    return _filePath;
}

void Attachment::setFilePath(const QString& path) {
    _filePath = path;
}
