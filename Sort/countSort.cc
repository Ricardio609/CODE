#include "countSort.h"

void countSort(vector<int>& raw) {
    //确保待排容器非空
    if (raw.size() == 0)    return;
    vector<int> obj(raw.size(), 0);

    //使用raw的最大值 + 1作为计数容器的大小
    int countLength = (*max_element(begin(raw), end(raw))) + 1;
    vector<int> count(countLength, 0);

    //统计每个键值出现的次数
    for (int i = 0; i < raw.size(); ++i) {
        count[raw[i]]++;
    }

    //后面的键值出现的位置为前面所有键值出现的次数之和
    for (int i = 1; i < countLength; ++i) {
        count[i] += count[i - 1];
    }
    
    //将键值放到目标位置
    for (int i = raw.size(); i > 0; --i) {      //此处逆序是为了保持相同键值的稳定性
        obj[--count[raw[i - 1]]] = raw[i - 1];
    }
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