#include <iostream>
#include <vector>
using namespace std;

//时间负复杂度O(n^2)，空间O（1），非稳定排序，原地排序
void selectionSort_v1(vector<int>& a, int len) {
    int minIndex = 0;
    for(int i = 0; i < len; ++i) {
        minIndex = i;
        for(int j = i + 1; j < len; ++j) {
            if(a[j] < a[minIndex])  minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

void selectionSort_v2(vector<int>& nums) {
    int len = nums.size();
    int minIndex = 0;

    for(int i = 0; i < len; ++i) {
        minIndex = i;
        for(int j = i + 1; j < len; ++j) {
            if(nums[j] < nums[minIndex])  minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
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
    // selectionSort_v1(a, a.size());
    selectionSort_v2(a);
    display(a);
    return 0;
}
