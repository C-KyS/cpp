#include <iostream>

class CDate
{
public:
    CDate();
    CDate(int year, int month, int day);

    int GetDaysOfMonth(int year, int month);
    void Print() const; // 打印日期

    CDate &operator++();
    CDate operator++(int);

    CDate operator+=(long days);            // += 运算符重载, 若干天后日期
    CDate operator+(long days) const;       // 若干天后日期
    CDate operator-=(long days);            // -= 运算符重载, 若干天前日期
    CDate operator-(long days) const;       // 若干天前日期
    long operator-(const CDate &rhs) const; // 相差天数
    bool operator==(const CDate &rhs) const;      // == 运算符重载, 日期比较
    bool operator!=(const CDate &rhs) const;      // != 运算符重载, 日期比较

    static int IsLeapYear(int year); // 该年是否润年
    int WeekDay() const;             // 星期几

private:
    int m_year, m_month, m_day; // 年、月、日
};
// 该年是否润年
int CDate::IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// 获取某年某月的天数
int CDate::GetDaysOfMonth(int year, int month)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year))
    {
        return 29; // 润年二月
    }
    else
    {
        return days[month - 1];
    }
}

// 打印日期
void CDate::Print() const
{
    std::cout << m_year << "-" << m_month << "-" << m_day << std::endl;
}

// 有参构造函数
CDate::CDate(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

//+= 运算符重载, 若干天后日期
CDate CDate::operator+=(long days)
{
    m_day += days;
    while (m_day > CDate::GetDaysOfMonth(m_year, m_month))
    {
        m_day -= CDate::GetDaysOfMonth(m_year, m_month);
        if (m_month == 12)
        {
            m_month = 1;
            m_year++;
        }
        else
            m_month++;
    }
    return *this;
}

// + 运算符重载,   若干天后日期
CDate CDate::operator+(long days) const
{
    CDate result = *this;
    result += days;
    return result;
}

// -= 运算符重载, 若干天前日期
CDate CDate::operator-=(long days)
{
    m_day -= days;
    while (m_day < 1)
    {

        if (m_month == 1)
        {
            m_month = 12;
            m_year--;
        }
        else
            m_month--;
        m_day += CDate::GetDaysOfMonth(m_year, m_month);
    }
    return *this;
}

// - 运算符重载, 若干天前日期
CDate CDate::operator-(long days) const
{
    CDate result = *this;
    result -= days;
    return result;
}

// 前置 ++运算符重载, ++d1
CDate &CDate::operator++()
{
    *this += 1;
    return *this;
}

// 后置 ++运算符重载, d1++
CDate CDate::operator++(int)
{
    CDate temp = *this;
    *this += 1;
    return temp;
}

// == 运算符重载, 日期比较
bool CDate::operator==(const CDate &rhs) const
{
    return this->m_year == rhs.m_year && this->m_month == rhs.m_month && this->m_day == rhs.m_day;
}

// != 运算符重载, 日期比较
bool CDate::operator!=(const CDate &rhs) const
{
    return !(*this == rhs);
}

// 相差天数, *this - rhs
long CDate::operator-(const CDate &rhs) const
{
    CDate temp = rhs;
    int cont = 0;
    while (*this != temp)
    {
        temp += 1;
        cont++;
    }
    return cont;
}

// 星期几
int CDate::WeekDay() const
{
    static const int monthOffset[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int year = m_year;
    int month = m_month;
    int day = m_day;

    // Sakamoto algorithm: returns 0=Sunday, 1=Monday, ..., 6=Saturday.
    if (month < 3)
    {
        year -= 1;
    }
    return (year + year / 4 - year / 100 + year / 400 + monthOffset[month - 1] + day) % 7;
}             

int main()
{
    CDate d1(2021, 1, 1);
    d1.Print();
    std::cout << "d1 weekday: " << d1.WeekDay() << std::endl; // 输出星期几

    (d1++).Print(); // 后置++，先打印再自增
    (++d1).Print(); // 前置++，先自增再打印

    CDate d2 = d1 + 10000; // 加30天
    d2.Print();
    std::cout << "d2 weekday: " << d2.WeekDay() << std::endl; // 输出星期几
    std::cout << "d2 - d1: "<< d2 - d1 << std::endl; // 计算相差天数


    return 0;
}
