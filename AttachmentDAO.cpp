#include "AttachmentDAO.h"
#include <QSqlQuery>
#include <QVariant>

AttachmentDAO::AttachmentDAO(): DAO("Attachment")
{
    addMapping("Title", "TITLE",    "varchar");
    addMapping("Path",  "PATH",     "varchar");
    createTable();
}

AttachmentDAO* AttachmentDAO::getInstance()
{
    static AttachmentDAO instance;
    return &instance;
}

Persistable* AttachmentDAO::createObject(int id) {
    return new Attachment(id);
}
