// map 所有的元素都是pair类型key-value,会根据的元素的key值自动排序（从小到大），不允许有重复的key值
// multimap，允许有重复的key值
// 插入数据要用队组pair
// 不建议使用m[x]=num进行赋值，不存在的m[x]会被赋值为0
// m.find(key)返回值的是迭代器     m.count(key)返回值是一个int，统计key的个数
// 使用仿函数进行重载()运算符,按照key进行排序,所以如果是自定义数据进行排序,将自定义数据设为key

#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "map"
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


class MyCompare
{
public:
    bool operator()(const int v1, const int v2)
    {
        return v1 > v2;
    }
};

class MyCompare2
{
public:
    bool operator()(Person v1,Person v2) 
    {
        if (v1.m_age == v2.m_age)
        {
            return v1.m_heigh<v2.m_heigh;
        }
        else
        {
            return v1.m_age<v2.m_age;
        }
    }
};



void setPerson(map< Person,int, MyCompare2> &m)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        int rand_age = rand() % 31 + 20; // 取值范围【n,m】rand()%m-n+1 + n;
        int rand_heigh = rand() % 21 + 160;
        string name = "选手";
        name += nameseed[i];
        Person p(name, rand_age, rand_heigh);
        m.insert(make_pair(p,i));
    }
}

void printset(map<Person,int, MyCompare2> &L)
{
    for (map<Person,int, MyCompare2>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout <<"id"<<it->second<< " name:" << it->first.m_name 
             << " age:" << it->first.m_age << " heigh:" << it->first.m_heigh;
        cout << endl;
    }
}




void printmap(map<int, int, MyCompare> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << (*it).first << " value:" << it->second << endl;
    }

    for (int i = 1; i <= m.size(); i++)
    {
        cout << m[i] << " ";
    }
}

void test()
{
    map<int, int, MyCompare> m;
    m.insert(pair<int, int>(1, 23));
    m.insert(make_pair(6, 29));
    m.insert(pair<int, int>(3, 23));
    m.insert(pair<int, int>(2, 23));
    m.insert(pair<int, int>(4, 23));
    m.insert(pair<int, int>(5, 23));
    if (!m.empty())
    {
        cout << m.size() << endl;
        map<int, int>::iterator pos = m.find(3);
        if (pos != m.end())
        {
            cout << "the find key:" << (*pos).first << " the value:" << pos->second << endl;
        }
    }

    printmap(m);
}

// 自定义数据类型
void test_paixun()
{
    srand((unsigned int)time(NULL));

    map<Person,int, MyCompare2> s;//自定义按person中的数据进行排序,则要把person放在<>左边第一个

    setPerson(s);
    printset(s);
}

int main(int argc, char *argv[])
{
    // test();
    test_paixun();
    return 0;
}
