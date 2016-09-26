#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryBase.h"

class Provider;
class Invoice;

class Library: public LibraryBase
{
public:
    static Library* getInstance();

    Provider* getProvider(int id);
    Invoice*  getInvoice (int id);

private:
    Library();
};

#endif // LIBRARY_H
