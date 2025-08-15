/*
! 290. 单词规律

给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s
中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false


提示:

1 <= pattern.length <= 300
pattern 只包含小写英文字母
1 <= s.length <= 3000
s 只包含小写英文字母和 ' '
s 不包含 任何前导或尾随对空格
s 中每个单词都被 单个空格 分隔
*/
#include <string>
#include <unordered_map>

using namespace std;

class Solution290 {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> dic;
        unordered_map<string, char> rev_dic;

        int pattern_size = pattern.size();
        int s_size = s.size();

        int idx = 0, jdx = 0;
        while (idx < pattern_size && jdx < s_size) {
            // 获取从jdx开始的第一个word
            while (jdx < s_size && s[jdx] == ' ') {
                jdx++;
            }
            int word_start = jdx;
            while (jdx < s_size && s[jdx] != ' ') {
                jdx++;
            }
            string word = s.substr(word_start, jdx - word_start);

            if (dic.find(pattern[idx]) != dic.end()) {
                if (dic[pattern[idx]] != word) {
                    return false;
                }

            } else {
                if (rev_dic.find(word) != rev_dic.end()) {
                    return false;
                }
                dic[pattern[idx]] = word;
                rev_dic[word] = pattern[idx];
            }
            idx++;
        }

        // s尾部空格去掉
        while (jdx < s_size && s[jdx] == ' ') {
            jdx++;
        }

        // 如果idx,jdx完成对string的遍历,则返回true, 否则返回false
        if (idx == pattern_size && jdx == s_size) {
            return true;
        }
        return false;
    }
};