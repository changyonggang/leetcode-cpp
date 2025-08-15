/*
! 3. 无重复字符的最长子串

给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/
#include <string>
#include <unordered_map>

using namespace std;

class Solution3 {
   public:
    // 遍历字符串s,
    // 将字符放入hash-map中,如果出现了重复的字符,则更新最长子串的长度
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int len = s.size();
        int window_size = 0;
        int left = 0, right = 0;
        for (int idx = 0; idx < len; idx++) {
            window_size++;
            if (dic.find(s[idx]) != dic.end()) {
                right++;
                dic[s[idx]] = idx;
            } else {
                dic[s[idx]] = idx;
            }
        }
    }
};