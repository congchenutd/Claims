#include "Attachable.h"
#include "AttachableDAO.h"

#include <QSqlQuery>

AttachableDAO::AttachableDAO(const QString& tableName)
    : DAO(tableName)
{
}

void AttachableDAO::createAttachmentTable()
{
    addRelationships(Relationship(getTableName(), "Attachment"));
    createRelationshipTables();
}

void AttachableDAO::updateAttachments(Persistable* persistable)
{
    Attachable* attachable = static_cast<Attachable*>(persistable);
    QSqlQuery query;
    query.exec(tr("delete from %1").arg(getAttachmentTableName()));

    foreach (const Attachment& attachment, attachable->getAllAttachments())
        query.exec(tr("insert into %1 values (%2, %3)")
                        .arg(getAttachmentTableName())
                        .arg(attachable->getID())
                        .arg(attachment.getID()));
}

QString AttachableDAO::getAttachmentTableName() const {
    return getTableName() + "Attachment";
}
