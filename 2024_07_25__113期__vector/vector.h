#include <iostream>

template <class T>
class vector
{
    typedef T *iterator;

public:
    size_t size() const { return _end - _start; }
    size_t capacity() const { return _end_of_storage - _start; }

    void Reserve(size_t n)
    {
        if (n > capacity())
        {
            size_t old_size = size();

            T *tmp = new T[n];
            memcpy(tmp, _start, old_size * sizeof(T));
            delete[] _start;

            _start = tmp;
            _end = _start + old_size;
            _end_of_storage = _start + n;
        }
    }

private:
    iterator _start = nullptr;
    iterator _end = nullptr;
    iterator _end_of_storage = nullptr;
};


