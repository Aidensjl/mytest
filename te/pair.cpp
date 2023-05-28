// pair对组

#include "stdlib.h"
#include "iostream"
#include "algorithm"

using namespace std;

void test()
{
    pair<string,int> p2("tom",12);
    pair<string,int> p= make_pair("tom",12);


    cout<<p.first <<"   "<<p.second;

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
