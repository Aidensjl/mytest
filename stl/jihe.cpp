// 容器v1和容器v2是升序的
// set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),tar.begin()); 返回值是"交集"中最后一个位置的迭代器
// set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), tar.begin());返回值是"并集"中最后一个位置的迭代器
// set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), tar.begin()); v1和v2相比，返回值是"差集"中最后一个位置的迭代器
// set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), tar.begin()); v2和v1相比，返回值是"差集"中最后一个位置的迭代器


#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "numeric"
#include "functional"
#include "vector"

using namespace std;

void Myprint(int val)
{
    cout << val << " ";
}
vector<int> v1{1, 2, 3, 4, 5, 6, 7};
vector<int> v2{0, 2, 3, 4, 5};
vector<int> tar;

void test01()
{

    tar.resize(min(v1.size(),v2.size()));//分配空间
    // tar.resize(v1.size() < v2.size() ? v1.size() : v2.size());

    vector<int>::iterator posend = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),tar.begin());
    for_each(tar.begin(),posend,Myprint);//注意结束迭代器是posend,不是tar.end()

}

void test02()
{
    tar.resize(v1.size() + v2.size());
    vector<int>::iterator posend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), tar.begin());
    for_each(tar.begin(), posend, Myprint); // 注意结束迭代器是posend,不是tar.end()

}

void test03()
{
    tar.resize(max(v1.size(),v2.size()));
    vector<int>::iterator posend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), tar.begin());

    cout<<"v1 和 v2 的差集：";
    for_each(tar.begin(), posend, Myprint); // 注意结束迭代器是posend,不是tar.end()
    cout<<endl;
    posend = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), tar.begin());
    cout<<"v2 和 v1 的差集：";
    for_each(tar.begin(), posend, Myprint); // 注意结束迭代器是posend,不是tar.end()
}

int main(int argc, char *argv[])
{
    test01();//交集
    cout<<endl;
    test02();//并集
    cout<<endl;
    test03();//差集
    return 0;
}
