#include "bubbleSort.h"
#include "countSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "shellSort.h"

#include <ctime>

int main() {
    srand((unsigned)time(NULL));
    const int N = 100000;//测试数据个数
    vector<int> a1(N);
    vector<int> a2(N);
    vector<int> a3(N);
    vector<int> a4(N);
    vector<int> a5(N);
    vector<int> a6(N);
    vector<int> a7(N);
    vector<int> a8(N);


    //给开辟数组赋值
    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand();
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
        a8[i] = a1[i];
    }
    cout << "开始排序" << endl;
    
    //数组排序并计算时间花费
    int begin1 = clock();
    insertionSort(a1, N);
    int end1 = clock();
 
    int begin2 = clock();
    shellSort(a2);
    int end2 = clock();
 
    int begin3 = clock();
    selectionSort_v2(a3);
    int end3 = clock();
 
    int begin4 = clock();
    heapify_sort(a4, N);
    int end4 = clock();
 
    int begin5 = clock();
    quickSort(a5, 0, N - 1);
    int end5 = clock();
 
    int begin6 = clock();
    mergeSort(a6);
    int end6 = clock();
 
    int begin7 = clock();
    bubbleSort_v3(a7);
    int end7 = clock();
 
    int begin8 = clock();
    countSort(a8);
    int end8 = clock();
    //展示数据
    cout << "InsertSort: " << end1 - begin1 << endl;
    cout << "ShellSort: " << end2 - begin2 << endl;
    cout << "SelectSort: " << end3 - begin3 << endl;
    cout << "HeapSort: " << end4 - begin4 << endl;
    cout << "QuickSort: " << end5 - begin5 << endl;
    cout << "MergeSort: " <<  end6 - begin6 << endl;
    cout << "BubbleSort: " << end7 - begin7 << endl;
    cout << "CountSort: " << end8 - begin8 << endl;

    return 0;
}