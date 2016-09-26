#ifndef CLAIMDAO_H
#define CLAIMDAO_H

#include "AttachableDAO.h"
#include "Claim.h"

class ClaimDAO: public AttachableDAO
{
public:
    static ClaimDAO* getInstance();

    Claim* load(int id) const;

protected:
    Persistable* createObject(int id);

private:
    ClaimDAO();
};

#endif // CLAIMDAO_H
