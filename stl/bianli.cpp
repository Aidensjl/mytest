// for_each 遍历
// transform 搬运,过程中可以进行运算

#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "numeric"
#include "functional"
#include "vector"

using namespace std;

class Transform
{
public:
    int operator()(int val)
    {
        return 1-val;
    }
};

class MyPrint_class
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void MyPrint(int val)
{
    cout << val << " ";
}

// for_each 遍历
void test01()
{
    vector<int> v{0, 1, 4, 2, 5, 3, 7};
    // 第三个参数 A unary function object：Apply a function to every element of a sequence.
    // 普通函数，使用函数名（是一个函数指针）
    for_each(v.begin(), v.end(), MyPrint);
    cout << endl;
    // 仿函数，使用匿名函数对象
    for_each(v.begin(), v.end(), MyPrint_class());

    cout << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
}

// transform 搬运
void test02()
{
    // 起始容器
    vector<int> v{0, 1, 4, 2, 5, 3, 7};
    // 目标容器
    vector<int> target;

    target.resize(v.size());

    transform(v.begin(), v.end(), target.begin(),Transform());

    for_each(target.begin(),target.end(),MyPrint_class());
}

int main(int argc, char *argv[])
{
    // test01();
    test02();
    return 0;
}
