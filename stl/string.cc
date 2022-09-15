#include <bits/stdc++.h>    //万能头文件，基本包含了大部分STL库函数
#include <iostream>
using namespace std;

int main()
{
    string s;
    string t = "m";
    cin >> s;   //不包含空格
    getline(cin, s);    //读取一行，可以包含空格
    s.append(t);    //将字符t添加的到s
    cout << s + t << endl;

    string s1, s2;
    cin >> s1 >> s2;

    //两个字符串的大小关系
    cout << (s1 == s2) << endl;
    cout << (s1 > s2) << endl;
    cout << (s1 < s2) << endl;

    //find(“字符串”) / find("字符串",postion) ---找不到就返回很大很大的数,可以与-1比较
    if (s1.find(s2) == -1)
    {
        cout << "在s1中未找到" << endl;
    }

    cout << s.find(t) << endl;  //找子序列t在s中出现的首个位置
    cout << s.find(t, 2) << endl;  //从第二个位置开始找，找子序列t在s中出现的首个位置

    int len = s.size();
    int len1 = s.length();

    reverse(s.begin(), s.end());

    string s1 = "hello";
    string sTemp = s.substr(1);     //从下标一开始到字符串结束
    string sTemp1 = s.substr(1,3);  //从下标一开始，截取3个字符

    //第一个元素 s[0] 


    s1.insert(1, "b");
    s1.erase(1, 2); //在位置1删除两个字符

    //int to string
    s1 = to_string(123456);
    //string to int
    int x = stoi("1234");   //stol是转换成长整型s
}
