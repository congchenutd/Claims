#ifndef ATTACHABLEDAO_H
#define ATTACHABLEDAO_H

#include "DAO.h"

class Persistable;

class AttachableDAO: public DAO
{
protected:
    AttachableDAO(const QString& tableName);
//    void updateAttachments(Persistable* persistable);

private:
    QString getAttachmentTableName() const;
};

#endif // ATTACHABLEDAO_H
