#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
! 1657. 确定两个字符串是否接近
中等
相关标签
premium lock icon
相关企业
提示
如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 接近 ：

操作 1：交换任意两个 现有 字符。
例如，abcde -> aecdb
操作 2：将一个 现有 字符的每次出现转换为另一个 现有
字符，并对另一个字符执行相同的操作。 例如，aacabb -> bbcbaa（所有 a 转化为 b
，而所有的 b 转换为 a ） 你可以根据需要对任意一个字符串多次使用这两种操作。

给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true
；否则，返回 false 。



示例 1：

输入：word1 = "abc", word2 = "bca"
输出：true
解释：2 次操作从 word1 获得 word2 。
执行操作 1："abc" -> "acb"
执行操作 1："acb" -> "bca"
示例 2：

输入：word1 = "a", word2 = "aa"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
示例 3：

输入：word1 = "cabbba", word2 = "abbccc"
输出：true
解释：3 次操作从 word1 获得 word2 。
执行操作 1："cabbba" -> "caabbb"
执行操作 2："caabbb" -> "baaccc"
执行操作 2："baaccc" -> "abbccc"
提示：

1 <= word1.length, word2.length <= 105
word1 和 word2 仅包含小写英文字母
*/

class Solution1657 {
   public:
    bool closeStringsMy(string word1, string word2) {
        // 将 word1 和 word2 中每个字符的出现个数分别放到 dic1 和 dic2 中
        unordered_map<char, int> dic1, dic2;
        for (char c : word1) {
            if (dic1.find(c) == dic1.end()) {
                dic1[c] = 1;
            } else {
                dic1[c]++;
            }
        }
        for (char c : word2) {
            if (dic2.find(c) == dic2.end()) {
                dic2[c] = 1;
            } else {
                dic2[c]++;
            }
        }
        // 将 dic1 和 dic2 中相同的元素去掉, 做元素的交换, 如果最终 dic1 和 dic2
        for (auto it = dic1.begin(); it != dic1.end();) {
            if (dic2[it->first] == it->second) {
                dic2.erase(it->first);
                it = dic1.erase(it);
            } else {
                it++;
            }
        }

        // unordered_map<char, int> dic3;
        vector<int> char_count_v;
        for (auto it = dic1.begin(); it != dic1.end(); it++) {
            // dic3[it->first] = dic2[it->first] + it->second;
            char_count_v.push_back(dic2[it->first] + it->second);
        }
        sort(char_count_v.begin(), char_count_v.end());
        // 相同, 则 word1 和 word2 相近
        int len = char_count_v.size();
        if (len % 2 != 0) {
            return false;
        }
        for (int idx = 0; idx + 1 < len; idx = idx + 2) {
            if (char_count_v.at(idx) != char_count_v.at(idx + 1)) {
                return false;
            }
        }

        return true;
    }

    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        unordered_map<char, int> freq1, freq2;
        for (char c : word1) {
            freq1[c]++;
        }
        for (char c : word2) {
            freq2[c]++;
        }

        // 1. 字符集合必须相同
        if (freq1.size() != freq2.size()) {
            return false;
        }
        for (auto& [c, _] : freq1) {
            if (!freq2.count(c)) {
                return false;
            }
        }

        // 2. 字符频率的集合必须相同
        vector<int> count1, count2;
        for (auto& [_, v] : freq1) {
            count1.push_back(v);
        }
        for (auto& [_, v] : freq2) {
            count2.push_back(v);
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
    }
};