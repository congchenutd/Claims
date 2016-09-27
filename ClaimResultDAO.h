#ifndef CLAIMRESULTDAO_H
#define CLAIMRESULTDAO_H

#include "AttachableDAO.h"

class ClaimResultDAO : public AttachableDAO
{
public:
    static ClaimResultDAO* getInstance();

protected:
    Persistable* createObject(int id);

private:
    ClaimResultDAO();
};

#endif // CLAIMRESULTDAO_H
