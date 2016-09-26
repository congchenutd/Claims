#ifndef ATTACHMENT_H
#define ATTACHMENT_H

#include "Persistable.h"

#include <QString>

class Attachment: public Persistable
{
    Q_OBJECT
    Q_PROPERTY(QString Title    READ getTitle   WRITE setTitle)
    Q_PROPERTY(QString Path     READ getPath    WRITE setPath)

public:
    Attachment(const Attachment& another);
    Attachment& operator = (const Attachment& another);
    Attachment(int id);

    QString getTitle() const;
    void setTitle(const QString& title);

    QString getPath() const;
    void setPath(const QString& path);

private:
    QString _title;
    QString _filePath;
};

#endif // ATTACHMENT_H
