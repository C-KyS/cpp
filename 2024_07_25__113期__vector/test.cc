#include "vector.h"

int main()
{
    vector<int> vec;
    std::cout << vec.capacity() << std::endl;

    vec.Reserve(1024*1024);
    std::cout << vec.capacity() << std::endl;

    vec.Reserve(32);
    std::cout << vec.capacity() << std::endl;

    return 0;
}