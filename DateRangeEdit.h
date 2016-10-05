#ifndef DATERANGEEDIT_H
#define DATERANGEEDIT_H

#include <QWidget>

class QDateEdit;

class DateRangeEdit : public QWidget
{
    Q_OBJECT
public:
    explicit DateRangeEdit(QWidget* parent = 0);

    QDate getStartDate() const;
    QDate getEndDate  () const;

    void setStartDate(const QDate& date);
    void setEndDate  (const QDate& date);

private:
    QDateEdit* _start;
    QDateEdit* _end;
};

#endif // DATERANGEEDIT_H
