#ifndef ATTACHABLE_H
#define ATTACHABLE_H

#include "Attachment.h"
#include "Persistable.h"
#include <QList>

class Attachable: public Persistable
{
public:
    Attachable(int id, DAO* dao);
    virtual ~Attachable() = 0;

    void addAttachment(const Attachment& attachment);
    QList<Attachment> getAllAttachments() const;

protected:
    QList<Attachment> _attachments;
};

#endif // ATTACHABLE_H
