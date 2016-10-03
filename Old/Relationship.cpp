#include "Relationship.h"

Relationship::Relationship(const QString& mainTableName, const QString& foreignTableName)
    : _mainTableName(mainTableName),
      _foreignTableName(foreignTableName)
{}

QString Relationship::getMainTableName() const {
    return _mainTableName;
}

QString Relationship::getForeignTableName() const {
    return _foreignTableName;
}

QString Relationship::getMainID() const {
    return _mainTableName + "ID";
}

QString Relationship::getForeignID() const {
    return _foreignTableName + "ID";
}

QString Relationship::getRelationshipTableName() const {
    return _mainTableName + _foreignTableName;
}
