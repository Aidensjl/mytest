// 查找算法
// find 返回值是一个元素位置迭代器
// find_if 返回值是一个元素位置迭代器
// adjacent_find 查找相邻重复元素，返回值是第一个相邻元素位置的迭代器
// binary_search 查找是否存在某个元素，返回值是bool类型，只能在“升序有序序列”中使用
// count 统计容器中的个数,返回值是个数
// count_if 按条件统计容器中的个数,返回值是个数

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
    bool operator==(const Person &p)//底层重载,要const
    {
        if (this->m_name == p.m_name && this->m_age == p.m_age)
        {
            return true;
        }
        else
            return false;
    }

    string m_name;
    int m_age;
};

void test01()
{
    vector<int> v{0, 1, 4, 2, 5, 3, 7};
    // 查找内置数值
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end())
    {
        cout << *pos << endl;
    }
    else
    {
        cout << "no find" << endl;
    }
}

void test02()
{
    // 查找自定义数据类型，需要重载操作符
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

    Person person2("ee", 20); // 判断person2是否在容器中

    vector<Person>::iterator it = find(person.begin(), person.end(), person2);
    if (it == person.end())
    {
        cout << "no find" << endl;
    }
    else
    {
        cout << it->m_name << it->m_age << endl;
    }
}

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test03()
{
    // 按照条件判断来查找find_if
    vector<int> v{0, 1, 4, 2, 5, 3, 7};
    // 查找内置数值
    /*
    // 输出全部大于4的数
    for (int i = 0; i < v.size(); i++)
    {
        vector<int>::iterator pos = v.begin() + i;
        if (pos != v.end() && (*pos) > 4)
        {
            cout << *pos << endl;
        }
        else
        {
            cout << "no find" << endl;
        }
    } */
    // 查找第一个大于5的数
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if (pos != v.end() && (*pos) > 4)
    {
        cout << *pos << endl;
    }
    else
    {
        cout << "no find" << endl;
    }
}

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_age > 20;
    }
};

void test04()
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

    // 查找年龄大于20的人
    vector<Person>::iterator pos = find_if(person.begin(), person.end(), Greater20());
    if (pos != person.end())
    {
        cout << (*pos).m_name << (*pos).m_age << endl;
    }
    else
    {
        cout << "no find" << endl;
    }
}

void test05()
{
    vector<int> v{1, 2, 4, 3, 5, 6, 6, 5, 7, 4, 3};

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos != v.end())
    {
        cout << *pos << endl;
    }
    else
    {
        cout << "None" << endl;
    }
}

// 全局函数
bool Mycompare(int v1, int v2)
{
    return v1 > v2;
}

// 仿函数
class Mycompare_class
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test06()
{
    vector<int> v = {1, 2, 3, 4, 4, 6, 3};

    // sort(v.begin(),v.end(),Mycompare);//降序，全局函数
    // sort(v.begin(),v.end(),Mycompare_class());//降序，仿函数
    // sort(v.begin(),v.end(),greater<int>());//greater<int>()
    sort(v.begin(), v.end());

    for (auto i : v)
    {
        cout << i << " ";
    }
    bool res = binary_search(v.begin(), v.end(), 3);
    if (res)
    {
        cout << "find it" << endl;
    }
    else
        cout << "no find it" << endl;
}

void test07()
{
    // vector<int> v = {1, 2, 3, 4, 4, 6, 3};
    // int num = count(v.begin(),v.end(),4);
    // cout<<num<<endl;
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

    Person pp("sss",50);

    int num = count(person.begin(),person.end(),pp);//重载==
    cout<<num<<endl;

}

int main(int argc, char *argv[])
{
    // test01(); // find 查找某个值
    // test02(); // find 查找自定义数据的某个值，重载()
    // test03(); // find_if 按照条件查找某个值，仿函数
    // test04(); // find_if 按照条件查找自定义数据的某个值
    // test05();//adjacent_find 查找相邻相同元素
    // test06();//bianry_search 升序有序序类中的二分查找，返回值是bool类型
    test07(); // count 统计个数
    return 0;
}
