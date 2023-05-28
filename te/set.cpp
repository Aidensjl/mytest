// set 容器,升序，只能insert插入，不能push_back()，不能存在重复值
// multiset 容器，可以重复

#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "set"
#include "string"

using namespace std;

class Person
{
public:
    Person(string name, int age, int heigh)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_heigh = heigh;
    }

    string m_name;
    int m_age;
    int m_heigh;
};

// 仿函数重载（）
class MyCompare
{
public:
    bool operator()(Person v1, Person v2)
    {
        if (v1.m_age == v2.m_age)
        {
            return v1.m_heigh<v2.m_heigh;
        }
        else
        {
            return v1.m_age < v2.m_age;
        }
    }
};

void setPerson(set<Person, MyCompare> &L)
{
    string s = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        int rand_age = rand() % 31 + 20; // 取值范围【n,m】rand()%m-n+1 + n;
        int rand_heigh = rand() % 21 + 160;
        string name = "选手";
        name += s[i];
        Person p(name, rand_age, rand_heigh);
        L.insert(p);
    }
}

void test()
{
    multiset<int> s{1, 3, 4, 2, 5};
    s.insert(0); // 插入

    s.insert(0); // 插入
    // s.erase(0);//删除
    for (int i : s)
    {
        cout << i << " ";
    }
    // find(key)：查找元素，返回的是一个迭代器，如果没有找到，返回set.end();
    set<int>::iterator pos = s.find(0);
    if (pos != s.end())
    {
        cout << "find:" << *pos << endl;
    }
}

void printset(set<Person, MyCompare> &L)
{
    for (set<Person, MyCompare>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "name:" << it->m_name << " age:" << it->m_age << " heigh:" << it->m_heigh;
        cout << endl;
    }
}

void test_paixun()
{
    srand((unsigned int)time(NULL));

    set<Person, MyCompare> s;

    setPerson(s);
    printset(s);
}

int main(int argc, char const *argv[])
{
    test();
    // test_paixun();
    return 0;
}
