#include "Date.hpp"

void test01()
{
    // Date d1;
    // Date d2(2021, 12, 31);

    // d1.Print();
    // d2.Print();

    // Date d3 = d1;
    // d3.Print();
    // d3 += 100000;
    // d3.Print();

    Date d4(1900, 2, 28);
    d4.Print();
    d4 += 100000;
    d4.Print();
}

void test02()
{
    Date d1(2026, 4, 11);
    d1.Print();
    Date d2 = d1 + 100000;
    d1.Print();
    d2.Print();
}

int main()
{
    // test01();
    test02();
    return 0;
}

