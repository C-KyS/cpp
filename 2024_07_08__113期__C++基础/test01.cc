// #include <iostream>
// #include <stdlib.h>

// // int a = 0;

// namespace cyh
// {
//     int a =1;
//     int b = 2;
// } // namespace cyh

// // int a =1;
// using cyh::a;

// int main()
// {
//     std::cout << a <<std::endl;
//     std::cout << cyh::b << std::endl;

//     return 0;
// }

// #include <iostream>
// int main()
// {
//     int a = 1;
//     double b = 2.0;
//     char c = 'c';

//     std::cout << a << " " << b << " " << c << std::endl;

//     return 0;
// }

#include <iostream>

int fun1(int a = 1, int b = 2, int c = 3)
{
    return a + b + c;
}

int main()
{
    std::cout << fun1(4) << std::endl;
    std::cout << fun1(4, 5) << std::endl;
    std::cout << fun1(4, 5, 6) << std::endl;
    return 0;
}