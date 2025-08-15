/*
! 45. 跳跃游戏 II

给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i]
处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i]
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。



示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3
步到达数组的最后一个位置。 示例 2:

输入: nums = [2,3,0,1,4]
输出: 2


提示:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
题目保证可以到达 nums[n-1]
*/
#include <vector>

using namespace std;

//~ 45题, 需要后面看一下
class Solution45 {
   public:
    // 使用贪心
    int jump(vector<int>& nums) {
        int opt = 0;
        int dest = nums.size() - 1;
        int step_sum = 0;
        int current_end = 0;
        int current_fastest = 0;

        for (int idx = 0; idx < dest; idx++) {
            current_fastest = max(current_fastest, idx + nums[idx]);
            if (idx == current_end) {  // 到达当前跳跃边界
                step_sum++;
                current_end = current_fastest;  // 更新新的跳跃边界
            }
        }

        return step_sum;
    }
};