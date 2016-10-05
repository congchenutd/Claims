#include "DateRangeEdit.h"

#include <QDateEdit>
#include <QHBoxLayout>

DateRangeEdit::DateRangeEdit(QWidget* parent)
    : QWidget(parent)
{
    _start = new QDateEdit(QDate::currentDate());
//    _start->setCalendarPopup(true);
    _end   = new QDateEdit(QDate::currentDate());
//    _end->setCalendarPopup(true);
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(_start);
    layout->addWidget(_end);
    layout->setContentsMargins(0, 0, 0, 0);
}

QDate DateRangeEdit::getStartDate() const {
    return _start->date();
}

QDate DateRangeEdit::getEndDate() const {
    return _end->date();
}

void DateRangeEdit::setStartDate(const QDate& date) {
    _start->setDate(date);
}

void DateRangeEdit::setEndDate(const QDate& date) {
    _end->setDate(date);
}
