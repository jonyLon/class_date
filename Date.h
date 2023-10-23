#pragma once
#include <iostream>
#include <string>
using namespace std;
class mDate
{
private:
	int day{}, month{}, year{};
	bool isLeapYear(int year)const;
	int daysInMonth(int month, int year)const;
	int dateToDays() const;
public:
	mDate() = default;
	mDate(int day, int month, int year) {
		if (day < 1 || day > 31 || month > 12 || month < 1) {
			cout << "Invalid date" << endl;
			return;
		}
		this->day = day;
		this->month = month;
		this->year = year;
	};
	void print() {
		string date = "";
		date += (day < 10 ? "0" + to_string(day) : to_string(day)) + ".";
		date += (month < 10 ? "0" + to_string(month) : to_string(month)) + ".";
		date += to_string(year);
		char* data_char = new char[date.length() + 1];
		strcpy_s(data_char, date.length() + 1, date.c_str());
		cout << data_char << endl;
	}

	int operator-(const mDate& other) const;
	bool operator==(const mDate& other) const;
	bool operator!=(const mDate& other) const;
	bool operator<(const mDate& other) const;
	bool operator>(const mDate& other) const;
	void operator+=(int days);
	void operator-=(int days);
};