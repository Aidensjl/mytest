// stl中的list容器，链表且双向的
#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "list"
#include "string"

using namespace std;

class Person
{
public:
    Person(string &name, int &age, int &heigh)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_heigh = heigh;
    }

    string m_name;
    int m_age;
    int m_heigh;
};

void printlist(list<Person> &L)
{
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "name:" << it->m_name << " age:" << it->m_age << " heigh:" << it->m_heigh;
        cout << endl;
    }
}
// 制定排序规则
// bool myCompare(Person &v1, Person &v2)
// {
//     if (v1.m_age == v2.m_age)
//     {
//         return v1.m_heigh < v2.m_heigh;
//     }
//     else
//     {
//         return v1.m_age < v2.m_age;
//     }
// }
// 仿函数方法
class myCompare
{
public:
    bool operator()(Person &v1, Person &v2)
    {
        if (v1.m_age == v2.m_age)
        {
            return v1.m_heigh < v2.m_heigh;
        }
        else
        {
            return v1.m_age < v2.m_age;
        }
    }
};

void setPerson(list<Person> &L)
{
    string s = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        int rand_age = rand() % 31 + 20; // 取值范围【n,m】rand()%m-n+1 + n;
        int rand_heigh = rand() % 21 + 160;
        string name = "选手";
        name += s[i];
        Person p(name, rand_age, rand_heigh);
        L.push_back(p);
    }
}

void test()
{
    srand((unsigned int)time(NULL)); // 随机数种子

    list<Person> L;
    setPerson(L);

    L.sort(myCompare()); // 重新定义高级比较，匿名函数对象

    printlist(L);
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}
