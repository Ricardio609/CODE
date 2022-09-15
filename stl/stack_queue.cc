#include <bits/stdc++.h>    //万能头文件，基本包含了大部分STL库函数
#include <iostream>
using namespace std;

int main()
{
    stack<int> s;

    for (int i = 0; i < 6; ++i)
    {
        s.push(i);
    }

    //访问栈顶元素
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();    //删除栈顶元素，但不返回该值
    cout << s.empty() << endl;



    queue<int> qu;
    for (int i = 0; i < 6; ++i)
    {
        qu.push(i);
    }

    //访问队首元素
    cout << qu.front() << endl;
    //访问队尾元素
    cout << qu.back() << endl;
    qu.pop();
    cout << qu.empty() << endl;
}