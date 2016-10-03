#ifndef DAO_H
#define DAO_H

#include "Relationship.h"

#include <QObject>

class Persistable;

/**
 * DAO is the interface for all DAO classes
 * Each DAO subclass manages the read/write of its corresponding
 * model class (Persistable) from/to database
 */
class DAO: public QObject
{
public:
    DAO(const QString& tableName): _tableName(tableName) {}

    // Save the persistable object into the database
    void save   (Persistable* persistable);

    // Whether the persistable exists in the database
    bool exists (Persistable* persistable) const;

    QString getTableName() const;

    int getNextID() const;

    // Load the persistable with the given id
    virtual Persistable* load(int id) const = 0;

    // delete the persistable and its relations
    virtual void remove(Persistable* persistable);

protected:
    virtual void createTable() = 0;

    // update an existing persistable
    virtual void update(Persistable* persistable) = 0;

    // insert a new persistable into db
    virtual void insert(Persistable* persistable) = 0;

    // update relations of a persistable
    void updateRelationships(Persistable* persistable);

    void addRelationships(const Relationship& relationship);
    QList<Relationship> getAllRelationships() const;

    void createRelationshipTables();

    // remove all relations of a persistable
    void removeRelationships(Persistable* persistable);

    // insert relations of a persistable into db
    virtual void insertRelationships(Persistable*) {}

private:
    // db table name of the persistable
    QString _tableName;

    QList<Relationship> _relationships;
};

#endif // DAO_H
