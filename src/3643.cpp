#include <vector>

using namespace std;

class Solution3643 {
   public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid,
                                         int x,
                                         int y,
                                         int k) {
        int n = grid.size();
        if (n == 0)
            return grid;
        int m = grid[0].size();
        if (x + k > n || y + k > m)
            return grid;  // 边界检查

        // 上下交换
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + k - 1 - j]);
            }
        }

        // 如果 k 是奇数，处理中间行
        if (k % 2 == 1) {
            int mid = k / 2;
            for (int j = 0; j < k / 2; j++) {
                swap(grid[x + mid][y + j], grid[x + mid][y + k - 1 - j]);
            }
        }

        return grid;
    }
};
