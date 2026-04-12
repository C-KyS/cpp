#include <iostream>

// 判断是否为闰年
bool IsLeapYear(int year);

class Date
{
public:
    // 默认构造, 全缺省, 2000-01-01
    Date(int year = 2000, int month = 1, int day = 1);

    // 根据年, 月获取该月天数
    int GetYearMonthDays(int year, int month)
    {
        static int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && IsLeapYear(year))
            return 29;
        else
            return days[month];
    }

    // += 运算符重载, 以天为单位
    Date &operator+=(int days);
    // + 运算符重载, 以天为单位
    Date operator+(int days);

    // -= 运算符重载, 以天为单位
    Date &operator-=(int days);
    // - 运算符重载, 以天为单位
    Date operator-(int days);

    // - 运算符重载, 日期相减, 以天为单位, d2 - d1
    int operator-(const Date &other);

    // < 重载
    bool operator<(const Date &other);
    // <= 重载
    bool operator<=(const Date &other);
    // > 重载
    bool operator>(const Date &other);
    // >= 重载
    bool operator>=(const Date &other);
    // == 重载
    bool operator==(const Date &other);
    // != 重载
    bool operator!=(const Date &other);

    // 前置++重载, 以天为单位, ++date
    Date& operator++();
    // 后置++重载, 以天为单位, date++
    Date operator++(int);

    // 打印日期, 格式: 2000-01-01
    void Print()
    {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

private:
    int _year;
    int _month;
    int _day;
};
