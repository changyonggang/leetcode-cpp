/*
! 242. 有效的字母异位词
简单

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。



示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false


提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母


进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution242 {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dic;
        for (char c : s) {
            if (dic.find(c) != dic.end()) {
                dic[c] = dic[c] + 1;
            } else {
                dic[c] = 1;
            }
        }

        for (char c : t) {
            if (dic.find(c) == dic.end() || dic[c] == 0) {
                return false;
            }
            dic[c] = dic[c] - 1;
        }

        for (pair<char, int> kv : dic) {
            if (kv.second > 0) {
                return false;
            }
        }

        return true;
    }
};