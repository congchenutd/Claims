#ifndef LIBRARYDAO_H
#define LIBRARYDAO_H

class Library;

class LibraryDAO
{
public:
    static LibraryDAO* getInstance();

    void load(Library* library);
    void save(Library* library);

private:
    LibraryDAO();
    ~LibraryDAO();
};

#endif // LIBRARYDAO_H
