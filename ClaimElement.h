#ifndef CLAIMELEMENT_H
#define CLAIMELEMENT_H

#include <Persistable.h>

class DAO;

class ClaimElement : public Persistable
{
    Q_OBJECT

public:
    ClaimElement(int id, DAO* dao);

    virtual ClaimElement* createNextElement() const;
    virtual QList<ClaimElement*> createSupportingElements() const;

    ClaimElement* getNext() const;
    void setNext(ClaimElement* next);

protected:
    ClaimElement* _next;
};

#endif // CLAIMELEMENT_H
