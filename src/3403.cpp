
/*
! 3403. 从盒子中找出字典序最大的字符串 I
中等

提示
给你一个字符串 word 和一个整数 numFriends。

Alice 正在为她的 numFriends 位朋友组织一个游戏。游戏分为多个回合，在每一回合中：

word 被分割成 numFriends 个 非空 字符串，且该分割方式与之前的任意回合所采用的都
不完全相同 。 所有分割出的字符串都会被放入一个盒子中。
在所有回合结束后，找出盒子中 字典序最大的 字符串。



示例 1：

输入: word = "dbca", numFriends = 2

输出: "dbc"

解释:

所有可能的分割方式为：

"d" 和 "bca"。
"db" 和 "ca"。
"dbc" 和 "a"。
示例 2：

输入: word = "gggg", numFriends = 4

输出: "g"

解释:

唯一可能的分割方式为："g", "g", "g", 和 "g"。



提示:

1 <= word.length <= 5 * 103
word 仅由小写英文字母组成。
1 <= numFriends <= word.length
*/

#include <string>

using namespace std;

// 这个题目是否可以转化为寻找word中长度为word.length - numFriends + 1
// 的最大子串,采用滑动窗口的思想,记录最大的子串;
// 需要注意这个滑动窗口,滑动规则如下: 滑动窗口大小为1到 word.length - numFriends
// + 1
class Solution3403 {
   public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        string max_sub_str = "";

        int left = 0;
        int sub_str_max_size = word.size() - numFriends + 1;
        while (left < word.size()) {
            int window_size = 1;
            while (left + window_size <= word.size() &&
                   window_size <= sub_str_max_size) {
                string sub_str = word.substr(left, window_size);
                printf("debug, sub_str: %s \n", sub_str.c_str());
                if (sub_str > max_sub_str) {
                    max_sub_str = sub_str;
                }
                window_size++;
            }

            left++;
        }

        return max_sub_str;
    }
};