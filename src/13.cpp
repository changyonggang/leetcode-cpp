/*
! 13. 罗马数字转整数
~ 简单
相关标签
相关企业
提示
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27
写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做
IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值
4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。



示例 1:

输入: s = "III"
输出: 3
示例 2:

输入: s = "IV"
输出: 4
示例 3:

输入: s = "IX"
输出: 9
示例 4:

输入: s = "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: s = "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.


提示：

1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
关于罗马数字的详尽书写规则，可以参考 罗马数字 - 百度百科。
*/

#include <string>

using namespace std;

class Solution13 {
   public:
    int romanToInt(string s) {
        int idx = 0;
        int sum = 0;
        while (true) {
            pair<int, int> item = core(s, idx);
            if (item.first < 1) {
                return sum;
            }
            sum = sum + item.first;
            idx = item.second;
        }
    }

    // pair left 是解析成功的二进制, right 为最新的游标
    pair<int, int> core(string s, int idx) {
        if (idx >= s.size()) {
            return make_pair(0, s.size());
        } else if (idx + 1 < s.size()) {
            // 1. 匹配两个字符的case
            string sub_str = s.substr(idx, 2);
            if (sub_str == "IV") {
                return make_pair(4, idx + 2);
            } else if (sub_str == "IX") {
                return make_pair(9, idx + 2);
            } else if (sub_str == "XL") {
                return make_pair(40, idx + 2);
            } else if (sub_str == "XC") {
                return make_pair(90, idx + 2);
            } else if (sub_str == "CD") {
                return make_pair(400, idx + 2);
            } else if (sub_str == "CM") {
                return make_pair(900, idx + 2);
            } else {
                // 2. 匹配一个字符的case
                if (s[idx] == 'I') {
                    return make_pair(1, idx + 1);
                } else if (s[idx] == 'V') {
                    return make_pair(5, idx + 1);
                } else if (s[idx] == 'X') {
                    return make_pair(10, idx + 1);
                } else if (s[idx] == 'L') {
                    return make_pair(50, idx + 1);
                } else if (s[idx] == 'C') {
                    return make_pair(100, idx + 1);
                } else if (s[idx] == 'D') {
                    return make_pair(500, idx + 1);
                } else if (s[idx] == 'M') {
                    return make_pair(1000, idx + 1);
                }
            }

        } else {
            // 3. 匹配一个字符的case
            if (s[idx] == 'I') {
                return make_pair(1, idx + 1);
            } else if (s[idx] == 'V') {
                return make_pair(5, idx + 1);
            } else if (s[idx] == 'X') {
                return make_pair(10, idx + 1);
            } else if (s[idx] == 'L') {
                return make_pair(50, idx + 1);
            } else if (s[idx] == 'C') {
                return make_pair(100, idx + 1);
            } else if (s[idx] == 'D') {
                return make_pair(500, idx + 1);
            } else if (s[idx] == 'M') {
                return make_pair(1000, idx + 1);
            }
        }
    }
};