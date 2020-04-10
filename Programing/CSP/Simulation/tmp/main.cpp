#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int> mp;
int main()
{
//清空
mp.clear();

//大小
mp.size();

//插入键值对
mp[key]=value;

//顺序遍历
for(auto it = mp.begin();it!=mp.end();++it)
{
    int key = it->first;
    int calue = it->second;
}

    return 0;
}
