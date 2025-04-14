
#include <iostream>
#include <string>

using namespace std;
// LeetCode 58. 最后一个单词的长度
class Solution {
  public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;
        // 从后往前遍历字符串
        for (int i = n - 1; i >= 0; i--) {
            // 如果遇到空格，且已经开始计算单词长度，则退出循环
            if (s[i] == ' ' && length > 0) {
                break;
            }
            // 如果不是空格，则增加单词长度
            if (s[i] != ' ') {
                length++;
            }
        }
        return length;
    }

    int lengthOfLastWord2(string s) {
        int n = s.size();
        int length = 0;
        // 从后往前遍历字符串
        for (int i = n - 1; i >= 0; i--) {
            // 如果遇到空格，且已经开始计算单词长度，则退出循环
            if (s[i] == ' ' && length > 0) {
                break;
            }
            // 如果不是空格，则增加单词长度
            if (s[i] != ' ') {
                length++;
            }
        }
        return length;
    }
};