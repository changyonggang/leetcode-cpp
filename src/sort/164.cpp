/*
! 164. 最大间距
中等
相关标签
premium lock icon
相关企业
给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值
。如果数组元素个数小于 2，则返回 0 。

您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。



示例 1:

输入: nums = [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值
3。 示例 2:

输入: nums = [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。


提示:

1 <= nums.length <= 105
0 <= nums[i] <= 109

*/

#include <vector>

using namespace std;

// 时间复杂度为 O(n) 的排序为 基数排序,即根据每个数据的个位\十位\百位排序;
// 从低到高, 第一轮,个位排序, 第二轮十位排序, 第三轮百位排序
// 或者从高到低,
class Solution164 {
   public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
    }

    int getMax(vector<int>& nums) {
        int max = nums[0];
        for (const int item : nums) {
            if (item > max) {
                max = item;
            }
        }

        return max;
    }

    // 提取某个数在第 d 位（最高位为 d = maxDigit）上的值
    int getDigit(int num, int d) {
        return (num / static_cast<int>(pow(10, d))) % 10;
    }

    void radixSortMSD(vector<int>& nums) {
        int max = getMax(nums);
        int maxDigit = log10(max);
        radixSortCore(nums, 0, nums.size() - 1, maxDigit);
    }

    void radixSortCore(vector<int>& nums, int start, int end, int digit) {
        if (start >= end || digit < 0)
            return;

        const int RADIX = 10;
        vector<int> buckItemCount(RADIX, 0);  // 存储每个桶的大小

        for (int i = start; i <= end; i++) {
            int d = getDigit(nums[i], digit);
            buckItemCount[d]++;
        }

        vector<int> buckStartIndex(RADIX, 0);  // 存储每个桶的起始index
        for (int i = 1; i < RADIX; i++) {
            buckStartIndex[i] = buckStartIndex[i - 1] + buckItemCount[i];
        }

        vector<int> tmp(end - start + 1);  // 10个桶
        // 将元素放入 10 个桶中
        for (int i = start; i <= end; i++) {
            int d = getDigit(nums[i], digit);
            // 存入第d个桶中
            tmp[buckStartIndex[d]] = nums[i];
            buckStartIndex[d]++;
        }

        // copy 10 个桶中元素到原数组
        for (int i = 0; i < tmp.size(); ++i) {
            nums[start + i] = tmp[i];
        }

        buckStartIndex[0] = 0;
        for (int i = 1; i < RADIX; i++) {
            buckStartIndex[i] = buckStartIndex[i - 1] + buckItemCount[i];
        }

        // 递归处理每一个桶内元素
        for (int i = 0; i < RADIX; i++) {
            radixSortCore(nums, buckStartIndex[i],
                          buckStartIndex[i] + buckItemCount[i], digit - 1);
        }
    }
};
