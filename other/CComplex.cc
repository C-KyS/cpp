#include <iostream>

class CComplex
{
    friend std::ostream &operator<<(std::ostream &out, const CComplex &c);

public:
    // 全缺省, 默认构造函数
    CComplex(double r = 0, double i = 0)
    {
        _real = r;
        _imag = i;
    }

    // 重载 + 运算符
    CComplex operator+(const CComplex &c)
    {
        CComplex temp;
        temp._real = _real + c._real;
        temp._imag = _imag + c._imag;
        return temp;
    }

    // 重载 - 运算符
    CComplex operator-(const CComplex &c)
    {
        CComplex temp;
        temp._real = _real - c._real;
        temp._imag = _imag - c._imag;
        return temp;
    }

    // 重载 * 运算符
    CComplex operator*(const CComplex &c)
    {
        CComplex temp;
        temp._real = _real * c._real - _imag * c._imag;
        temp._imag = _real * c._imag + _imag * c._real;
        return temp;
    }

    // 重载 = 运算符
    CComplex operator=(const CComplex &c)
    {
        _real = c._real;
        _imag = c._imag;
        return *this;
    }

    

    // 析构函数
    ~CComplex()
    {
    }

private:
    double _real;
    double _imag;
};

// 重载 << 运算符
std::ostream &operator<<(std::ostream &out, const CComplex &c)
{
    std::string sign = c._imag > 0 ? "+" : "";
    out << c._real << sign << c._imag << "i";
    return out;
}



int main()
{
    CComplex c1(2, 3);
    CComplex c2(4, 5);
    CComplex c3 = c1 + c2;
    CComplex c4 = c1 - c2;
    CComplex c5 = c1 * c2;
    CComplex c6 = c1;
    c6 = c2;

    std::cout << c1 << std::endl; // 输出 2 + 3i
    std::cout << c2 << std::endl; // 输出 4 + 5i
    std::cout << c3 << std::endl; // 输出 6 + 8i
    std::cout << c4 << std::endl; // 输出 -2 - 2i
    std::cout << c5 << std::endl; // 输出 -7 + 22i
    std::cout << c6 << std::endl; // 输出 4 + 5i
    return 0;
}
