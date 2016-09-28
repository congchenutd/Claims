#ifndef ATTACHMENT_H
#define ATTACHMENT_H

#include "ClaimElement.h"

#include <QString>

class Attachment: public ClaimElement
{
    Q_OBJECT
    Q_PROPERTY(QString Title    READ getTitle   WRITE setTitle)
    Q_PROPERTY(QString Path     READ getPath    WRITE setPath)

public:
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
