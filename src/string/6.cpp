/*

6. Z 字形变换

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z
字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);


示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"


提示：

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution6 {
   public:
    // 模拟z,将string
    string convert_my(string s, int numRows) {
        // 1. 如果 numRows 为 1, 或者 numRows 不大于 s 的length
        if (numRows == 1 || numRows <= s.length()) {
            return s;
        }

        // 模拟存储二维数组中
        int cols = s.length();
        char mat[numRows][cols];
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < cols; j++)
                mat[i][j] = '0';

        // 二维数组更新时,分两种情况,一种是向下运动,一种是向右上角方向
        int s_len = s.length();
        int x = 0, y = 0;
        bool forward_down = true;
        int j = 0, k = 0;

        for (int i = 0; i < s_len; i++) {
            mat[x][y] = s[i];

            // 转换方向
            if (j == numRows - 1) {
                forward_down = false;
                j = 0;
            }

            if (forward_down) {  // 向下移动
                x++;
                j++;
            } else {  // 向右上移动
                x--;
                y++;
                k++;
            }

            // 转换方向
            if (k == numRows) {
                forward_down = true;
                k = 0;
            }
        }

        char result[cols];
        k = 0;
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < cols; j++)
                if (mat[i][j] != '0') {
                    result[k] = mat[i][j];
                    k++;
                }

        return result;
    }

    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        int t = r * 2 - 2;
        int c = (n + t - 1) / t * (r - 1);
        vector<string> mat(r, string(c, 0));
        for (int i = 0, x = 0, y = 0; i < n; ++i) {
            mat[x][y] = s[i];
            if (i % t < r - 1) {
                ++x;  // 向下移动
            } else {
                --x;
                ++y;  // 向右上移动
            }
        }
        string ans;
        for (auto& row : mat) {
            for (char ch : row) {
                if (ch) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};