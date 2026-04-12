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

void test03()
{
    Date d1(2026, 4, 11);
    d1.Print();
    
    d1 -= 100000;
    d1.Print();
}

void test04()
{
    Date d1(2024, 7, 13);
    d1.Print();
    
    Date d2 = d1 - 3000;
    d1.Print();
    d2.Print();
}

void test05()
{
    Date d1(2024, 7, 12);
    Date d2(2024, 7, 13);
    Date d3(2024, 7, 14);

    std::cout << (d1 < d1) << std::endl;
    d1.Print();
    std::cout << (d1 < d2) << std::endl;
    d2.Print();
    std::cout << (d3 < d2 + 100000) << std::endl;
    (d2 + 100000).Print();
}


int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    return 0;
}

