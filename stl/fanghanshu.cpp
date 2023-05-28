// 仿函数_函数对象
// pred谓词(重载为bool型的operator())
#include "stdlib.h"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Myprint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
        ;
        (this->count)++;
    }

    int count = 0;
};

void call(Myprint &p, string text)
{
    p(text);
}

void test()
{
    Myprint myprint;

    call(myprint, "he");

    myprint("hello");
    myprint("hello");
    // myprint("hello");
    // myprint("hello");
    // myprint("hello");

    cout << myprint.count;
}

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v{1, 2, 43, 5, 3, 32, 56, 7, 4};

    // for (int i = 0; i < 7; i++)
    // {
    //     v.push_back(i);
    // }
    // GreaterFive() 匿名函数对象

    for (int i = 0; i < v.size(); i++)
    {
        // vector<int>::iterator pos = find_if(v.begin()+i, v.end(), GreaterFive());
        vector<int>::iterator pos = v.begin()+i;
        if (pos != v.end() && (*pos)>5 )
        {
            cout << "大于5 the value:" << (*pos) << endl;
        
        }
        else
        {
            cout << "none" << endl;
        }
    }

    // if (pos != v.end())
    // {
    //     cout << "大于5 the value:" << (*pos) << endl;
    // }
    // else
    // {
    //     cout<<"none"<<endl;
    // }
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
