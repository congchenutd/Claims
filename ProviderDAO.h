#ifndef PROVIDERDAO_H
#define PROVIDERDAO_H

#include "DAO.h"
#include "Provider.h"

class ProviderDAO: public DAO
{
public:
    static ProviderDAO* getInstance();

    Provider* load(int id) const;

protected:
    void createTable();

private:
    ProviderDAO();
    ~ProviderDAO() {}
    void update(Persistable* persistable);
    void insert(Persistable* persistable);
};

#endif // PROVIDERDAO_H
