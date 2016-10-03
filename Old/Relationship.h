#ifndef RELATIONSHIPDAO_H
#define RELATIONSHIPDAO_H

#include <QString>

class Relationship
{
public:
    Relationship(const QString& mainTableName, const QString& foreignTableName);

    QString getMainTableName() const;
    QString getForeignTableName() const;
    QString getMainID() const;
    QString getForeignID() const;
    QString getRelationshipTableName() const;

private:
    QString _mainTableName;
    QString _foreignTableName;
};

#endif // RELATIONSHIPDAO_H
