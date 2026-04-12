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

// - 运算符重载, 日期相减, 以天为单位, d2 - d1
int Date::operator-(const Date &other)
{
    int days1 = 0;
    for (int month = 1; month < _month; month++)
    {
        days1 += GetYearMonthDays(_year, month);
    }
    days1 += _day - 1;
    std::cout << "days1: " << days1 << std::endl;

    int days2 = 0;
    for (int year = other._year; year < _year; year++)
    {
        days2 += IsLeapYear(year) ? 366 : 365;
    }
    std::cout << "days2: " << days2 << std::endl;

    int days3 = 0;
    for (int month = 1; month < other._month; month++)
    {
        days3 += GetYearMonthDays(other._year, month);
    }
    days3 += other._day - 1;
    std::cout << "days3: " << days3 << std::endl;

    std::cout << "days1 + days2 - days3: " << days1 + days2 - days3 << std::endl;
    return days1 + days2 - days3;
}

// == 重载
bool Date::operator==(const Date &other)
{
    return _year == other._year && _month == other._month && _day == other._day;
}
// != 重载
bool Date::operator!=(const Date &other)
{
    return !(*this == other);
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
    return *this < other || *this == other;
}
// > 重载
bool Date::operator>(const Date &other)
{
    return !(*this <= other);
}
// >= 重载
bool Date::operator>=(const Date &other)
{
    return *this > other || *this == other;
}

// 前置++重载, 以天为单位, ++date
Date &Date::operator++()
{
    *this += 1;
    return *this;
}
// 后置++重载, 以天为单位, date++
Date Date::operator++(int)
{
    Date tmp = *this;
    *this += 1;
    return tmp;
}
