#include "countSort.h"

void countSort(vector<int>& raw) {
    //确保待排容器非空
    if (raw.size() <= 1)    return;
   
    // 1、计算最大值和最小值
    int max = *max_element(raw.begin(), raw.end());
    int min = *min_element(raw.begin(), raw.end());
    
    // 2、开辟长度为（max - min + 1）的数组，即为计数排序的空间复杂度
    vector<int> countArray(max - min + 1, 0);       //数据量过大时，内存不足，无法创建countArray
    
    // 3、遍历数组计数
    int rawLength = raw.size();
    for (int i = 0; i < rawLength; ++i) {
        countArray[raw[i] - min]++;
    }
    
    // 4、排序
    vector<int> sortArray;
    int countArrayLength = countArray.size();
    for (int i = 0; i < countArrayLength; ++i) {
        for (int j = 0; j < countArray[i]; ++j) {
            sortArray.push_back(min + i);
        }
    }
    // return sortArray;
}

// int main() {
//     vector<int> raw = {0, 5, 7,9,6,3,4,5,2,8,6,9,2,1};
//     vector<int> obj(raw.size(), 0);

//     countSort(raw, obj);

//     for (int i = 0; i < obj.size(); ++i) {
//         cout << obj[i] << " ";
//     }
//     cout << endl;
// }