#ifndef ATTACHMENTDAO_H
#define ATTACHMENTDAO_H

#include "DAO.h"
#include "Attachment.h"

class Persistable;

class AttachmentDAO: public DAO
{
public:
    static AttachmentDAO* getInstance();

    Attachment* load(int id) const;

protected:
    void createTable();

private:
    AttachmentDAO();
    ~AttachmentDAO() {}
    void update(Persistable* persistable);
    void insert(Persistable* persistable);
};

#endif // ATTACHMENTDAO_H
