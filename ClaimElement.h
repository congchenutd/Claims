#ifndef CLAIMELEMENT_H
#define CLAIMELEMENT_H

#include <Persistable.h>

class DAO;

class ClaimElement : public Persistable
{
public:
    ClaimElement(int id, DAO* dao);
};

#endif // CLAIMELEMENT_H
