#ifndef ATTACHMENT_H
#define ATTACHMENT_H

#include "Persistable.h"

#include <QString>

class Attachment: public Persistable
{
public:
    Attachment(int id, const QString& title, const QString& filePath);

    QString getTitle() const;
    void setTitle(const QString& title);

    QString getFilePath() const;
    void setFilePath(const QString& path);

private:
    QString _title;
    QString _filePath;
};

#endif // ATTACHMENT_H
