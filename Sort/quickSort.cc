#include <iostream>
#include <vector>
using namespace std;



void quickSort(vector<int>& a, int low, int high) {
    if(low >= high)    //递归退出条件
        return;
    
    int first = low;
    int last = high;
    int key = a[first];     //设置当前队列第一个元素为基准

    while(first < last) {
        //从后往前走，将比基准小的元素移到前面
        while(first < last && a[last] > key) 
            last--;
        if(first < last) 
            a[first++] = a[last];
        //从前往后走，将比基准大的元素移到后面
        while(first < last && a[first] <= key)
            first++;
        if(first < last) 
            a[last--] = a[first];
    }

    a[first] = key;
    //前半部分递归
    quickSort(a, low, first - 1);
    //后半部分递归
    quickSort(a, first + 1, high);
}

void display(vector<int>& a) {
    for(auto num : a) {
        cout<< num<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> a{10, 8, 4, 6, 9, 10, 123, 6, 2, 14, 3, 8, 5};
    display(a);
    quickSort(a, 0, a.size() - 1);
    display(a);
}