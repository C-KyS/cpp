#include "Date.hpp"

// 判断是否为闰年
bool IsLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

// 默认构造, 全缺省, 2000-01-01
Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
}

// += 运算符重载, 以天为单位
Date &Date::operator+=(int days)
{
    _day += days;
    while (_day > GetYearMonthDays(_year, _month))
    {
        _day -= GetYearMonthDays(_year, _month);
        _month++;
        if (_month == 13)
        {
            _month = 1;
            _year++;
        }
    }
    return *this;
}

// + 运算符重载, 以天为单位, d2 = d1 + 1000
Date Date::operator+(int days)
{
    Date tmp = *this;
    tmp += days;
    return tmp;
}

// -= 运算符重载, 以天为单位
Date &Date::operator-=(int days)
{
    _day -= days;
    while (_day <= 0)
    {
        _month - 1 == 0 ? _month = 12, _year-- : _month--;
        _day += GetYearMonthDays(_year, _month);
    }
    return *this;
}
// - 运算符重载, 以天为单位
Date Date::operator-(int days)
{
    Date tmp = *this;
    tmp -= days;
    return tmp;
}

// == 重载
bool Date::operator==(const Date &other)
{
}
// != 重载
bool Date::operator!=(const Date &other)
{
}
// < 重载
bool Date::operator<(const Date &other)
{
    if (_year < other._year)
        return true;
    else if (_year == other._year && _month < other._month)
        return true;
    else if (_year == other._year && _month == other._month && _day < other._day)
        return true;
    else
        return false;
}
// <= 重载
bool Date::operator<=(const Date &other)
{
}
// > 重载
bool Date::operator>(const Date &other)
{
}
// >= 重载
bool Date::operator>=(const Date &other)
{
}
