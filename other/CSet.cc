// 设计并完成一个具有并、交、差、元素查找、元素插入、元素删除和复制功能的集合类CSet并测试。

#include <iostream>

class CSet {
    public:
        // 全缺省, 默认构造函数
        CSet(int cap = 10) {
            data = new int[cap];
            size = 0;
            capacity = cap;
        }

        // 显式拷贝构造函数
        CSet(const CSet& other) {
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        // 并集, 重载 | 运算符
        CSet operator|(const CSet& rhs) {
            CSet result(*this); // 复制当前集合
            for (int i = 0; i < rhs.size; i++) {
                if (result.find(rhs.data[i]) == -1) { // 如果元素不在结果集合中
                    result.insert(rhs.data[i]); // 插入元素
                }
            }
            return result;
        }

        // 交集, 重载 & 运算符
        CSet operator&(const CSet& rhs) {
            CSet result;
            for (int i = 0; i < size; i++) {
                if (rhs.find(data[i]) != -1) { // 如果元素在另一个集合中
                    result.insert(data[i]); // 插入元素
                }
            }
            return result;
        }


        // 差集
        CSet operator-(const CSet& rhs) {
            CSet result;
            for (int i = 0; i < size; i++) {
                if (rhs.find(data[i]) == -1) { // 如果元素不在另一个集合中
                    result.insert(data[i]); // 插入元素
                }
            }
            return result;
        }

        // 元素查找
        int find(int x) const
        {
            for (int i = 0; i < size; i++) {
                if (data[i] == x) {
                    return i;
                }
            }
            return -1;
        }

        // 元素插入
        void insert(int x) {
            if (size >= capacity) {
                // 扩容
                capacity *= 2;
                int *newData = new int[capacity];
                for (int i = 0; i < size; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }
            data[size++] = x;
        }

        // 元素删除
        void remove(int x) {
            int index = find(x);
            if (index != -1) {
                for (int i = index; i < size - 1; i++) {
                    data[i] = data[i + 1];
                }
                size--;
            }
        }

        // 复制
        CSet& operator=(const CSet& rhs) {
            if (this != &rhs) {
                delete[] data;
                capacity = rhs.capacity;
                size = rhs.size;
                data = new int[capacity];
                for (int i = 0; i < size; i++) {
                    data[i] = rhs.data[i];
                }
            }
            return *this;   
        }

        // 打印集合元素
        void Print() const {
            std::cout << "{ ";
            for (int i = 0; i < size; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << "}" << std::endl;
        }

        // 析构函数
        ~CSet() {
            delete[] data;
        }

    private:
        int *data; // 存储集合元素的动态数组
        int size;   // 集合当前元素个数
        int capacity; // 集合容量
};

int main()
{
    CSet set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    CSet set2;
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);

    CSet unionSet = set1 | set2; // 并集
    CSet intersectionSet = set1 & set2; // 交集
    CSet differenceSet = set1 - set2; // 差集

    std::cout << "set1: ";
    set1.Print();
    std::cout << "set2: ";
    set2.Print();

    std::cout << "union: ";
    unionSet.Print();
    std::cout << std::endl;

    std::cout << "intersection: ";
    intersectionSet.Print();
    std::cout << std::endl;

    std::cout << "difference: ";
    differenceSet.Print();
    std::cout << std::endl;

    return 0;
}