#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0)
            return;
        // 1. 将后k个元素存储到临时数组中
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }
        // 2. 将前n-k个元素向后移动k个位置
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        // 3. 将临时数组中的元素放到前k个位置
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }

    // 空间复杂度为O(1)的解法
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0)
            return;
        // 1. 将前n-k个元素翻转
        reverse(nums.begin(), nums.end() - k);
        // 2. 将后k个元素翻转
        reverse(nums.end() - k, nums.end());
        // 3. 将整个数组翻转
        reverse(nums.begin(), nums.end());
    }
};
