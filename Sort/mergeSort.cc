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


/*
 *  以下是vector类型的归并排序。
 */
/* vector类型的迭代 */
void mergeSortCore(vector<int>& data, vector<int>& dataTemp, int low, int high) {
    if(low >= high) return;
    int len = high - low, mid = low + len / 2;
    int start1 = low, end1 = mid;
    int start2 = mid + 1, end2 = high;
    
    mergeSortCore(data, dataTemp, start1, end1);
    mergeSortCore(data, dataTemp, start2, end2);

    int index = low;
    while(start1 <= end1 && start2 <= end2) {
        dataTemp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2++];
    }

    while(start1 <= end1)
        dataTemp[index++] = data[start1++];

    while(start2 <= end2)
        dataTemp[index++] = data[start2++];
    
    for(index = low; index <= high; ++index) {
        data[index] = dataTemp[index];
    }
}
void mergeSort(vector<int>& data) {
    int len = data.size();
    vector<int> dataTemp(len, 0);
    mergeSortCore(data, dataTemp, 0, len - 1);
}

/* vector类型的递归 */
void mergeSort_recursive(vector<int>& data) {
    int len = data.size();
    vector<int> dataTemp(len, 0);

    for(int seg = 1; seg < len; seg += seg) {
        for(int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int index = low, start1 = low, end1 = mid, start2 = mid, end2 = high;

            while(start1 < end1 && start2 < end2) {
                dataTemp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2];
            }

            while(start1 < end1) 
                dataTemp[index++] = data[start1];
            
            while(start2 < end2) 
                dataTemp[index++] = data[start2];
        }
        swap(data, dataTemp);
    }

    for(auto a : data)
        cout<<a<<" ";
}


void display(vector<int>& nums) {
    for(auto a : nums)
        cout<<a<<" ";
    cout<<endl;
}

int main() {
    vector<int> nums{5, 3, 5, 6, 1, 4, 9, 10, 6, 2};
    display(nums);
    // mergeSort(nums);
    mergeSort_recursive(nums);
    display(nums);
    
    return 0;
}