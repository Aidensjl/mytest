// accumulate(v.begin(),v.end(),num) num是一个起始累加值,头文件是numeric
// fill(v.begin(),v.end(),num) 填充算法,num是填充的数

#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "numeric"
#include "functional"
#include "vector"

using namespace std;

void test01()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    v.resize(20);
    int num = v.size();
    cout<<num<<endl;
    fill(v.begin()+(v.size()/2),v.end(),10);

    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;


}


int main(int argc, char *argv[])
{
    test01();
    return 0;
}
