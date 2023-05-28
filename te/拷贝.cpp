// copy(v.begin(),v.end(),tar.begin()),提前开辟空间resize()
// replace(v.begin(),v.end()，oldvalue,newvalue) 替换操作,将容器中的所有的值都替换
// replace_if(v.begin(),v.end(),_pred,newvalue) 按条件替换
// swap(v1,v2) 两个相同类型的容器

#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "numeric"
#include "functional"
#include "vector"

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;

    void operator=(const Person &p)
    {
        this->m_name = p.m_name;
        this->m_age = p.m_age;
    }
};

class Mychoose
{
public:
    bool operator()(int val)
    {
        return val > 6;
    }
};

class Mychoose2
{
public:
    bool operator()(Person p)
    {
        return p.m_age > 50;
    }
};

void test01()
{
    vector<int> v{1, 2, 4, 5, 3, 6, 7};

    replace_if(v.begin(), v.end(), Mychoose(), 10);

    for (auto i : v)
    {
        cout << i << " ";
    }
}

void test02()
{
    vector<Person> person;
    Person p1("aaa", 20);
    Person p2("ccc", 30);
    Person p3("ddd", 40);
    Person p4("eee", 60);
    Person p5("fff", 50);
    person.push_back(p1);
    person.push_back(p2);
    person.push_back(p3);
    person.push_back(p4);
    person.push_back(p5);

    Person pp("sss", 50);
    replace_if(person.begin(), person.end(), Mychoose2(), pp);
    for (auto i : person)
    {
        cout << i.m_name << " "<<i.m_age<<endl;
    }
}

int main(int argc, char *argv[])
{
    // test01();//replace_if(v.begin(),v.end(),_pred,newvalue)
    test02();// replace_if自定义数据类型
    return 0;
}
