#include "insertionSort.h"

//时间复杂度 on^2 空间 o1，稳定排序，原地排序

// void display(vector<int>& a, int len, int i) {
//     cout<<"step"<<i<<": ";
//     for(int j = 0; j < len; ++j) {
//         cout<<a[j]<<" ";
//     }
//     cout<<endl;
// }

void insertionSort(vector<int>& a, int len) {
    //默认第一个元素是被排好序的，在已排好序的序列中从后往前扫描
    for(int i = 1; i < len; ++i) {
        if(a[i] < a[i - 1]) {               //如果第i个元素大于第i-1个元素，则直接插入。相反，小于的话，则移动有效表后再插入
            int j = i - 1;
            int x =a[i];    //哨兵，即待排序元素
            
            while(j >= 0 && x < a[j]) {     //查找插入位置
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;
        }
        // display(a, len, i);
    }
}

/* output:
 * step1：1 9 5 6 2 3 
 * step2：1 5 9 6 2 3 
 * step3：1 5 6 9 2 3 
 * step4：1 2 5 6 9 3 
 * step5：1 2 3 5 6 9 
 */
// int main() {
//     vector<int> a{9, 1, 5, 6, 2, 3};
//     insertionSort(a, a.size());
//     return 0;
// }