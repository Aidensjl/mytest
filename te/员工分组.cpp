#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "map"
#include "vector"

using namespace std;

enum Part
{
    CEHUA = 0,
    MEISHU = 1,
    YANFA = 2
};

class Person
{
public:
    string m_name;
    string m_part;
    int m_age;
    int m_salary;
};

void creatPerson(vector<Person> &vWorker)
{
    string nameseed = "ABCDEF";
    for (int i = 0; i < nameseed.size(); i++)
    {
        Person p;
        string namebase = "员工";
        namebase += nameseed[i];
        p.m_name = namebase;
        p.m_salary = rand() % 10000 + 10000;
        vWorker.push_back(p);
    }
}

void setGroup(vector<Person> &vWorker, multimap<int, Person> &mWorker)
{

    for (Person i : vWorker)
    {
        // 随即分配部门信息
        int depID = rand() % 3;
        mWorker.insert(make_pair(depID, i));
    }
}

void showWorkerBygroup(multimap<int, Person> &mWorker)
{
    cout << "策划部门：" << endl;
    multimap<int, Person>::iterator pos = mWorker.find(CEHUA);
    int count = mWorker.count(CEHUA);
    int index = 0;
    for (; pos != mWorker.end() && index < count; pos++, index++)
    {
        cout << "id:" << pos->first << "\tname:" << pos->second.m_name << "\tsalary:" << pos->second.m_salary << endl;
    }
    cout << "销售部门：" << endl;
    pos = mWorker.find(MEISHU);
    count = mWorker.count(MEISHU);
    index = 0;
    for (; pos != mWorker.end() && index < count; pos++, index++)
    {
        cout << "id:" << pos->first << "\tname:" << pos->second.m_name << "\tsalary:" << pos->second.m_salary << endl;
    }
    cout << "研发部门：" << endl;
    pos = mWorker.find(YANFA);
    count = mWorker.count(YANFA);
    index = 0;
    for (; pos != mWorker.end() && index < count; pos++, index++)
    {
        cout << "id:" << pos->first << "\tname:" << pos->second.m_name << "\tsalary:" << pos->second.m_salary << endl;
    }
}

void test()
{
    srand((unsigned int)time(NULL));
    vector<Person> vWorker; // 创建的是一个容器，里面的person内容需要创建
    creatPerson(vWorker);

    // 分组
    multimap<int, Person> mWorker;
    setGroup(vWorker, mWorker);

    // 显示
    showWorkerBygroup(mWorker);
    // for(Person i:vWorker)
    // {
    //     cout<<"name:"<<i.m_name<<"\tsalary:"<<i.m_salary<<endl;
    // }
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
