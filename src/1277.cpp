#include <algorithm>
#include <vector>

using namespace std;

/*
! 1277. 统计全为 1 的正方形子矩阵
中等
相关标签
premium lock icon
相关企业
提示
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1
组成的 正方形 子矩阵的个数。



示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释：
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.
示例 2：

输入：matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.


提示：

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

// 遍历每个元素和对应的正方形个数
class Solution1277 {
   public:
    int countSquares(vector<vector<int>>& matrix) {
        int lines = matrix.size();
        if (lines < 1) {
            return 0;
        }
        int count = 0;
        int colums = matrix[0].size();
        for (int idx = 0; idx < lines; idx++) {
            for (int idy = 0; idy < colums; idy++) {
                if (matrix[idx][idy] == 0) {
                    continue;
                }
                int max_square_size = min(lines - idx, colums - idy);
                for (int size = 1; size <= max_square_size; size++) {
                    if (!isSquares(matrix, idx, idy, size)) {
                        break;
                    }
                    count++;
                }
            }
        }
        return count;
    }

    bool isSquares(vector<vector<int>>& matrix,
                   int start_x,
                   int start_y,
                   int square_size) {
        for (int i = 0; i < square_size; i++) {
            for (int j = 0; j < square_size; j++) {
                if (matrix[start_x + i][start_y + j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
