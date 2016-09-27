#ifndef ATTACHABLE_H
#define ATTACHABLE_H

#include "Attachment.h"
#include "ClaimElement.h"
#include <QList>

class Attachable: public ClaimElement
{
    Q_OBJECT
    Q_PROPERTY(Attachment* Attachment READ getAttachment WRITE setAttachment)

public:
    Attachable(int id, DAO* dao);

    Attachment* getAttachment() const;
    void setAttachment(Attachment* attachment);

protected:
    Attachment* _attachment;
};

#endif // ATTACHABLE_H
