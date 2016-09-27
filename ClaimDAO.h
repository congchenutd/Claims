#ifndef CLAIMDAO_H
#define CLAIMDAO_H

#include "AttachableDAO.h"

class ClaimDAO: public AttachableDAO
{
public:
    static ClaimDAO* getInstance();

protected:
    Persistable* createObject(int id);

private:
    ClaimDAO();
};

#endif // CLAIMDAO_H
