/*

! 209. 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ...,
numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0


提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104


进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n))
时间复杂度的解法。
*/

#include <vector>

using namespace std;

class Solution209 {
   public:
    int minSubArrayLenBak(int target, vector<int>& nums) {
        int siz = nums.size();
        int window_size = siz + 1;
        int tmp_sum = 0;

        for (int start = 0, end = 0, window_data_sum = 0; end < siz; end++) {
            while (window_data_sum < target && end < siz) {
                window_data_sum = window_data_sum + nums[end];
                end++;
            }
            if (end >= siz) {
                break;
            }

            // start 是否可以右移
            tmp_sum = window_data_sum;
            while (tmp_sum - nums[start] >= target) {
                tmp_sum = tmp_sum - nums[start];
                start++;
            }

            if ((end - start + 1) < window_size) {
                window_size = end - start + 1;
            }
        }

        if (window_size > siz) {
            return 0;
        }

        return window_size;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int min_window = len + 1;
        bool not_zero = false;
        for (int left = 0, right = 0; right < len;) {
            if (sum < target) {
                sum = sum + nums[right];
                right++;
            }
            while (sum >= target) {
                not_zero = true;
                if (right - left < min_window) {
                    min_window = right - left;
                    printf("%d, %d \n", left, right);
                }
                sum = sum - nums[left];
                left++;
            }
        }

        if (not_zero) {
            return min_window;
        }

        return 0;
    }
};