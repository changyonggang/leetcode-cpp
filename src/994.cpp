#include <vector>
using namespace std;

class Solution994 {
    vector<pair<int, int>> new_rotte_v;  // 当前这一分钟新腐烂的橘子
    int rotte_count = 0;
    int empty_count = 0;

    int lines = 0;
    int colums = 0;

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        lines = grid.size();
        if (lines < 1)
            return 0;
        colums = grid[0].size();

        init_rotte_v(grid);

        // 如果一开始就没有新鲜橘子
        if (rotte_count + empty_count == lines * colums) {
            return 0;
        }

        int steps = 0;
        while (!new_rotte_v.empty() &&
               (rotte_count + empty_count) < lines * colums) {
            mock_one_step(grid);
            steps++;
        }

        // 如果结束后还有新鲜橘子 -> 不可能完成
        if (rotte_count + empty_count < lines * colums) {
            return -1;
        }
        return steps;
    }

    void init_rotte_v(vector<vector<int>>& grid) {
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < colums; j++) {
                if (grid[i][j] == 2) {
                    new_rotte_v.push_back({i, j});
                    rotte_count++;
                } else if (grid[i][j] == 0) {
                    empty_count++;
                }
            }
        }
    }

    void mock_one_step(vector<vector<int>>& grid) {
        vector<pair<int, int>> new_rotte;

        for (auto item : new_rotte_v) {
            int x = item.first, y = item.second;
            // 上
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                rotte_count++;
                new_rotte.push_back({x - 1, y});
            }
            // 下
            if (x + 1 < lines && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                rotte_count++;
                new_rotte.push_back({x + 1, y});
            }
            // 左
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                rotte_count++;
                new_rotte.push_back({x, y - 1});
            }
            // 右
            if (y + 1 < colums && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                rotte_count++;
                new_rotte.push_back({x, y + 1});
            }
        }

        new_rotte_v = new_rotte;
    }
};
