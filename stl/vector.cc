#include <bits/stdc++.h>    //万能头文件，基本包含了大部分STL库函数
#include <iostream>
using namespace std;

int main()
{
    /* vector */
    vector<int> first;  //空vector，只是一个列表的头，里面没有元素
    vector<int> second(4, 100);     //初始化一个具有4个元素的vector，每个元素的初始值是100
    vector<int> third(second.begin(), second.end());    //通过其他vector的迭代器的方式，进行拷贝复制初始化
    vector<int> fourth(third);  //直接对其他vector的拷贝复制

    //将数组转换成vector，需要提供数组的首地址和地址偏移a
    int myints[] = {16, 2, 77};
    vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

    //指定内容进行构造
    vector<int> sixth = {1, 5, 4, 6};

    //二维vector初始化
    vector<vector<int>> vars;

    //size*size的矩阵，元素都是0
    int size = 10;
    vector<vector<int>> vars1(size, vector<int>(size, 0));


    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    //使用下标访问元素
    cout << test[0] << endl;
    //使用迭代器访问元素
    for (vector<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << *it <<endl;    //迭代器指向的是对象的引用，而不是值
    }

    //在第i个元素前插入a
    int i = 1, a = 5;
    test.insert(test.begin() + i, a);

    //删除元素
    test.erase(test.begin() + 1);
    //删除区间上的元素
    test.erase(test.begin() + 1, test.end() + 2);
    //容器大小
    cout << test.size() << endl;
    //容器是否为空
    cout << test.empty() << endl;

    //清空
    test.clear();

    //用sort()函数从小到大进行排序
    sort(test.begin(), test.end());
    //翻转数组
    reverse(test.begin(), test.end());

    cout << test[0] << endl;  //第一个元素
    cout << test[test.size()] << endl;    //最后一个元素

    //在有序数组中返回第一个大于等于元素a的下标，返回值是地址
    lower_bound(test.begin(), test.end(), a);
    //在有序数组中返回第一个大于元素a的下标，返回值是地址(通过减去首地址)
    upper_bound(test.begin(), test.end(), a) - test.begin();

    //定义迭代器方便得到元素值，相当于指针
    vector<int>::iterator it;

    it = upper_bound(test.begin(), test.end(), a);
    cout << (*it) << endl;    //这里返回的是第一个大于元素a的值

    //二维数组的初始化
    vector<vector<int>> two_arry(3);   //3*3的矩阵，默认行和列数相同

    //3*5的矩阵
    for (int i = 0; i < two_arry.size(); ++i)
    {
        two_arry[i].resize(5); //用resize()将每一行的元素设置为5个
    }

    //size()得到矩阵的行数，two_arry[0].size()得到列数
    cout << two_arry.size() << endl;     //打印的是行数

    vector<vector<int>> Array(3, vector<int>(5));

    vector<vector<int>> num = 
    {
        {1, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 0} };
}



