#ifndef ATTACHMENTDAO_H
#define ATTACHMENTDAO_H

#include "DAO.h"
#include "Attachment.h"

class Persistable;

class AttachmentDAO: public DAO
{
public:
    static AttachmentDAO* getInstance();

protected:
    Persistable* createObject(int id);

private:
    AttachmentDAO();
};

#endif // ATTACHMENTDAO_H
