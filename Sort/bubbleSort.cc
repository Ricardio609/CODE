#include <iostream>
#include <vector>
using namespace std;

//时间复杂度O（n^2),空间复杂度O（1），原地算法，稳定
void bubbleSort_v1(vector<int>& a, int n) {
    for(auto i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void bubbleSort_v2(vector<int>& nums) {
    int len = nums.size();
    for(auto i = 0; i < len - 1; ++i) {
        for(int j = 0; j < len - i - 1; ++j) {
            if(nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

//优化版本
void bubbleSort_v3(vector<int>& nums) {
    int len = nums.size();
    bool flag = false;                  //表示某一趟是否发生数据交换，若未交互，则表明数据已有序，退出。

    for(int i = 0; i < len -1; ++i) {
        flag = false;
        for(int j = 0; j < len - 1 - i; ++j) {
            if(nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

void display(vector<int>& a) {
    for (auto it = a.cbegin(); it != a.cend() ; ++it) 
        cout << *it << " ";
    cout<<endl;
}

int main() {
    vector<int> a{3, 1, 2, 4, 6, 5};
    display(a);
    // bubbleSort_v1(a, a.size());
    // bubbleSort_v2(a);
    bubbleSort_v3(a);
    display(a);
    return 0;
}