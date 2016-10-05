#ifndef CLAIMELEMENT_H
#define CLAIMELEMENT_H

#include <Persistable.h>

class DAO;

class ClaimElement : public Persistable
{
    Q_OBJECT

public:
    ClaimElement(int id, DAO* dao);

    virtual QList<ClaimElement*> createNextElements      () const;
    virtual QList<ClaimElement*> createSupportingElements() const;
};

#endif // CLAIMELEMENT_H
