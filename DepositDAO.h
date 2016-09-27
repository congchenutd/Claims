#ifndef DEPOSITDAO_H
#define DEPOSITDAO_H

#include "AttachableDAO.h"

class DepositDAO : public AttachableDAO
{
public:
    static DepositDAO* getInstance();

protected:
    Persistable* createObject(int id);

private:
    DepositDAO();
};

#endif // DEPOSITDAO_H
