#include <bits/stdc++.h>    //万能头文件，基本包含了大部分STL库函数
#include <iostream>
using namespace std;

int main()
{
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mp[x] = i;
    }

    for (auto v : mp)
    {
        cout << v.first << " " << v.second <<endl;
    }

    unordered_map<char, int> map;
    //插入元素
    map['a'] = 1;
    map.insert({{'b', 2}, {'c', 3}});
    
    //修改元素
    map['a'] = 0;

    //遍历方式1
    for (auto& a : map)
    {
        char key = a.first;
        int value = a.second;
    }
    
    //遍历方式2
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        char key = it->first;
        int value = it->second;
    }
    map.erase('a');
    map.erase(map.begin());

    if (map.find('a') != map.end())
        cout << "success" << endl;
    if (map.count('a') != 0)
        cout << "success" << endl;

    map.clear();
    map.empty();
    map.size();
}