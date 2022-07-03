#include <iostream>
#include <vector>
using namespace std;

/* 迭代 */
template<typename T>
void merge_Sort(T arr[], int len) {
    T* a = arr;
    T* b = new T[len];
    for(int seg = 1; seg < len; seg += seg) {
        for(int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            cout<<low<<" "<<mid<<" "<<high<<endl;
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while(start1 < end1 && start2 < end2) {
                b[k++] = a[start1] < a[start2] ? a[start1++]:a[start2++];
            }
            while(start1 < end1) {
                b[k++] = a[start1++];
            }
            while(start2 < end2) {
                b[k++] = a[start2++];
            }
        }
        swap(a, b);
        delete[] b;
    }
}

/* 递归 */
template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
    if(start >= end)    return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    merge_sort_recursive(arr, reg , start1, end1);
    merge_sort_recursive(arr, reg , start2, end2);

    int k = start;
    while(start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while(start1 <= end1) 
        reg[k++] = arr[start1++];
    while(start2 <= end2) 
        reg[k++] = arr[start2++];
    for(k = start; k <= end; k++) 
        arr[k] = reg[k];
}
//merge_sort
template<typename T>
void merge_sort(T arr[], const int len) {
    T reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

void mergeSortCore(vector<int>& data, vector<int>& dataTemp, int low, int high);

void mergeSort(vector<int>& data);

void mergeSort_recursive(vector<int>& data);

