#ifndef PROVIDERDAO_H
#define PROVIDERDAO_H

#include "DAO.h"
#include "Provider.h"

class ProviderDAO: public DAO
{
public:
    static ProviderDAO* getInstance();

protected:
    Persistable* createObject(int id);

private:
    ProviderDAO();
};

#endif // PROVIDERDAO_H
