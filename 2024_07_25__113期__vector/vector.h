#include <iostream>

template <class T>
class vector
{
    typedef T *iterator;

public:
    void Reserve(size_t n)
    {
        if (n > capacity())
        {
            T *tmp = new T[n];
            memcpy(tmp, _start, size() * sizeof(T));
            delete[] _start;

            _start = tmp;
            _end = _start + size();
            _capacity = _start + n;
        }
    }

private:
    iterator _start = nullptr;
    iterator _end = nullptr;
    iterator _end_of_storage = nullptr;
};
