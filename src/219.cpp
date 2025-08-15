/*
! 219. 存在重复元素 II
简单

给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j
，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回
false 。



示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false




提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution219 {
   public:
    // 第一思路用map来遍历
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> dic_data_idx;  // 存储值 -> 最近出现的位置
        for (int idx = 0; idx < len; idx++) {
            if (dic_data_idx.find(nums[idx]) == dic_data_idx.end()) {
                dic_data_idx[nums[idx]] = idx;
            } else {
                if (idx - dic_data_idx[nums[idx]] <= k) {
                    return true;
                }
                dic_data_idx[nums[idx]] = idx;
            }
        }

        return false;
    }
};