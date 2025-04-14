/*
169. 多数元素

给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数
大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。



示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2


提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    // 1. 遍历一遍 vector, 将结果放入map中, key为元素, value为出现的次数,
    // 空间复杂度为 O(n), 时间复杂度 O(n)

    // 2. 原地排序,中间位置的元素即是对应的元素, 空间复杂度为 O(1),
    // 时间复杂度 O(nlogn)

    // 3. 类似与原地排序,遍历vector,
    // 保证相邻的idx元素不相同,如果相同就向下查找第一个不一样的元素和其交换,vector最后一个元素即出现最多的元素;

    // 1. 遍历一遍 vector, 将结果放入map中, key为元素, value为出现的次数,
    // 空间复杂度为 O(n), 时间复杂度 O(n)
    int majorityElement(vector<int>& nums) {
        int sze = nums.size();
        unordered_map<int, int> elementCount;
        for (size_t i = 0; i < sze; i++) {
            if (elementCount.find(nums[i]) == elementCount.end()) {
                elementCount.insert({nums[i], 1});
            } else {
                elementCount[nums[i]] += 1;
            }
        }

        int maxCount = -1;
        int ret = nums[0];

        for (const auto& pair : elementCount) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                ret = pair.first;
            }
        }

        return ret;
    };

    // 3. 类似与原地排序,遍历vector,
    // 保证相邻的idx元素不相同,如果相同就向下查找第一个不一样的元素和其交换,vector最后一个元素即出现最多的元素;
    int majorityElement3(vector<int>& nums) {
        int s = nums.size();
        // 查看第i个元素是否和前一个元素相同,如果相同则需要exchange
        for (int i = 1; i < s; i++) {
            if (i + 1 >= s) {
                break;
            }

            if (nums[i] == nums[i - 1]) {
                // exchange
                int j = diffDataIdx(nums, i);
                if (j == -1) {
                    break;
                }
                exchange(nums, i, j);
            }
        }

        return nums[s - 1];
    };

    int diffDataIdx(vector<int>& nums, int i) {
        int idx = -1;

        int s = nums.size();
        for (int j = i + 1; j < s; j++) {
            if (nums[j] != nums[i]) {
                return j;
            }
        }
        return idx;
    };

    void exchange(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    };

    //! 官方答案: Boyer-Moore 投票算法
    int majorityElementBest(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
