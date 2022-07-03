#include "mergeSort.h"

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


// void display(vector<int>& nums) {
//     for(auto a : nums)
//         cout<<a<<" ";
//     cout<<endl;
// }

// int main() {
//     vector<int> nums{5, 3, 5, 6, 1, 4, 9, 10, 6, 2};
//     display(nums);
//     // mergeSort(nums);
//     mergeSort_recursive(nums);
//     display(nums);
    
//     return 0;
// }