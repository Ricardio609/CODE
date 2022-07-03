#include <vector>
#include <iostream>
using namespace std;

void heapify(vector<int>& nums, int n, int i) {
    int l = i * 2 + 1, r = i * 2 + 2;
    int max = i;
    if (l < n && nums[l] > nums[max])
        max = l;
    if (r < n && nums[r] > nums[max])
        max = r;
    if (max != l) {
        swap(nums[max], nums[i]);
        heapify(nums, n, max);
    }
}

void heapify_build(vector<int>& nums, int n) {
    int temp = (n - 2) / 2;
    for (int i = temp; i >= 0; --i) {
        heapify(nums, n, i);
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void heapify_sort(vector<int>& nums, int n) {
    heapify_build(nums, n);
    for (int i = 0; i < n; ++i) {
        swap(nums.front(), nums[n - i - 1]);
        heapify(nums, n - i - 1, 0);
    }
}