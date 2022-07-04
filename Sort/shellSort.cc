#include "shellSort.h"

/* 无论是插入排序还是冒泡排序，如果数组的最大值刚好是在第一位，要将它挪到正确的位置就需要 n - 1 次移动。
 * 也就是说，原数组的一个元素如果距离它正确的位置很远的话，则需要与相邻元素交换很多次才能到达正确的位置，这样是相对比较花时间了
 *
 * 希尔排序：优化插入排序，交换不相邻的元素以对数组的局部进行排序
 * 核心思想：采用插入排序的方法，先让数组中任意间隔为 h 的元素有序，刚开始 h 的大小可以是 h = n / 2,
 * 接着让 h = n / 4，让 h 一直缩小，当 h = 1 时，也就是此时数组中任意间隔为1的元素有序，此时的数组就是有序的
 */

void shellSortCore(vector<int>& nums, int gap, int i) {
    int inserted = nums[i];
    int j;
    //在插入时按组插入
    for(j = i - gap; j >= 0 && inserted < nums[j]; j -= gap)    //当gap为1时，此处可看作是插入排序中从后往前搜索，以找到插入的位置
        nums[j + gap] = nums[j];
    nums[j + gap] = inserted;
}

void shellSort(vector<int>& nums) {
    int len = nums.size();
    //分组，gap初始值为数组的一半
    for(int gap = len / 2; gap > 0; gap /= 2) {
        //对各个分组进行插入分组
        for(int i = gap; i < len; ++i) {
            //将nums[i]插入到所在分组正确的位置上
            shellSortCore(nums, gap, i);
        }
    }
}

// void display(vector<int> nums) {
//     for(auto a : nums) 
//         cout<<a<<" ";
//     cout<<endl;
// }

// int main() {
//     vector<int> a{10, 8, 4, 6, 9, 10, 123, 6, 2, 14, 3, 8, 5};
//     display(a);
//     shellSort(a);
//     display(a);
//     return 0;
// }