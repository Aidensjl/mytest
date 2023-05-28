// sort(v.begin(),v.end(),_pred) 对容器中的数据进行降序,可以采用谓词pred改变排序方式
// random_shuffle(v.begin(),v.end()) 打乱容器中的顺序,加上随机数中种子: srand((unsigned int)time(NULL));
// merge 合并两个有序的容器到另一个容器中,且依旧有序
// reverse(v.begin(),v.end()) 反转

#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "numeric"
#include "functional"
#include "vector"

using namespace std;


// merge排序

void Myprint(int val)
{
    cout<<val<<" ";
}

void test01()
{
    vector<int> v1{1,2,4,3,5,6,7};
    vector<int> v2{1,2,4,3,5,6,7};

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    vector<int> tar;

    tar.resize(v1.size()+v2.size());

    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),tar.begin());

    for_each(tar.begin(),tar.end(),Myprint);



}





int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));

    test01();
    return 0;
}
