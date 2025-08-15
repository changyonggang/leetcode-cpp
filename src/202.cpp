/*
! 202. 快乐数

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。



示例 1：

输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：

输入：n = 2
输出：false


提示：

1 <= n <= 231 - 1
*/

#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution202 {
   public:
    // 模拟算法流程,将每次运算结果数据(这个地方将数据的每个位按照从小到大排序,去掉0)存入set中,
    // 如果set中出现了重复数据,则代表不是快乐数字,如果最后变为1,则代表是快乐数字
    bool isHappy(int n) {
        set<string> s;
        while (n != 1) {
            string tmp = sortDataItem(n);
            if (s.find(tmp) != s.end()) {
                return false;
            }
            s.insert(tmp);
            n = algOpt(tmp);
        }

        return true;
    }

    int algOpt(string src) {
        vector<int> datas;
        int sum = 0;
        for (char c : src) {
            int data = c - '0';
            sum = sum + data * data;
        }

        return sum;
    }

    string sortDataItem(int src) {
        vector<char> datas;
        while (src > 0) {
            if (src % 10 != 0) {
                datas.push_back((char)(src % 10 + '0'));
            }
            src = src / 10;
        }
        sort(datas.begin(), datas.end());

        string s(datas.begin(), datas.end());
        return s;
    }
};