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
    const int N = 100000;   //测试数据个数
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
        a1[i] = rand() % 1000;
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
        a8[i] = a1[i];
    }

    // for (auto a : a1)
    //     cout << a << " ";
    // cout << endl;

    cout << "开始排序" << endl;
    
    //数组排序并计算时间花费
    clock_t begin1 = clock();
    insertionSort(a1, N);
    clock_t end1 = clock();
    cout << "insertionSort: " << end1 - begin1 << endl;

    clock_t begin2 = clock();
    shellSort(a2);
    clock_t end2 = clock();
    cout << "shellSort: " << end2 - begin2 << endl;

    clock_t begin3 = clock();
    selectionSort_v2(a3);
    clock_t end3 = clock();
    cout << "selectionSort: " << end3 - begin3 << endl;

    clock_t begin4 = clock();
    heapify_sort(a4, N);
    clock_t end4 = clock();
    cout << "heapSort: " << end4 - begin4 << endl;

    clock_t begin5 = clock();
    quickSort(a5, 0, N - 1);
    clock_t end5 = clock();
    cout << "quickSort: " << end5 - begin5 << endl;

    clock_t begin6 = clock();
    mergeSort(a6);
    clock_t end6 = clock();
    cout << "mergeSort: " <<  end6 - begin6 << endl;

    clock_t begin7 = clock();
    bubbleSort_v3(a7);
    clock_t end7 = clock();
    cout << "bubbleSort: " << end7 - begin7 << endl;

    clock_t begin8 = clock();
    countSort(a8);
    clock_t end8 = clock();
    cout << "countSort: " << end8 - begin8 << endl;

    cout << "结束排序" << endl;

    return 0;
}