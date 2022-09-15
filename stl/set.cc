#include <bits/stdc++.h>    //万能头文件，基本包含了大部分STL库函数
#include <iostream>
using namespace std;

int main()
{
    //set ⾥⾯的各元素是各不相同的（重复元素自动删除），⽽且 set 会按照元素
    //进⾏从⼩到⼤排序
    set<int> s;
    // s.insert(2);
    for (int i = 0; i < 6; ++i)
    {
        s.insert(i);
    }

    set<int>::iterator it = s.begin();
    for (it; it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto v : s)
    {
        cout << v << " ";
    }
    cout << endl;

    //查找某一个num值，返回的是迭代器，因此需要用*来输出
    cout << *s.find(2) << endl;
    s.erase(3);
    s.clear();
    s.size();
    s.empty();
}