#include "Date.h"


bool mDate::isLeapYear(int year) const
{
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 100 != 0) {
        return true;
    }
    else if (year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}
int mDate::daysInMonth(int month, int year) const{
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year)) {
        return days[month] + 1;
    }
    return days[month];
}
int mDate::dateToDays() const{
    int totalDays = 0;

    for (int y = 1990; y < this->year; ++y) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < this->month; ++m) {
        totalDays += daysInMonth(m, this->year);
    }

    totalDays += day;

    return totalDays;
}

int mDate::operator -(const mDate& other) const {
    int daysThis = this->dateToDays();
    int daysOther = other.dateToDays();

    int difference = daysThis - daysOther;

    if (difference < 0) {
        cout << "Invalid subtraction: the second date is later than the first one." << endl;
        return 0;
    }
    return difference;
}

bool mDate::operator==(const mDate& other) const
{
    return this->dateToDays() == other.dateToDays();
}

bool mDate::operator!=(const mDate& other) const
{
    return this->dateToDays() != other.dateToDays();
}

bool mDate::operator<(const mDate& other) const
{
    return this->dateToDays() < other.dateToDays();
}

bool mDate::operator>(const mDate& other) const
{
    return this->dateToDays() > other.dateToDays();
}

void mDate::operator+=(int days)
{
    while (days > 0) {
        int daysInThisMonth = daysInMonth(this->month, this->year);
        if (day + days <= daysInThisMonth) {
            this->day += days;
            return;
        }
        else {
            int daysToMonthEnd = daysInThisMonth - this->day + 1;
            days -= daysToMonthEnd;
            this->day = 1;
            this->month++;
            if (this->month > 12) {
                this->month = 1;
                this->year++;
            }
        }
    }
}

void mDate::operator-=(int days)
{
    while (days > 0) {
        int daysInThisMonth = daysInMonth(this->month, this->year);
        if (this->day - days > 0) {
            this->day -= days;
            return;
        }
        else {
            days -= this->day;
            this->month--;
            if (this->month < 1) {
                this->month = 12;
                this->year--;
            }
            this->day = daysInMonth(month, year);
        }
    }
}


