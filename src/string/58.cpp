/*

58. 最后一个单词的长度

给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中
最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。


示例 1：

输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为 5。
示例 2：

输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为 4。
示例 3：

输入：s = "luffy is still joyboy"
输出：6
解释：最后一个单词是长度为 6 的“joyboy”。


提示：

1 <= s.length <= 104
s 仅有英文字母和空格 ' ' 组成
s 中至少存在一个单词

*/

#include <string>

using namespace std;

class Solution58 {
   public:
    int lengthOfLastWord(string s) {
        int len = s.length(), idx = len - 1;
        while (idx > 0 && s[idx] == ' ') {
            idx--;
        }

        int ret = 0;
        while (idx> 0 && s[idx] != ' ') {
            ret++;
            idx--;
        }

        return ret;
    }

    int lengthOfLastWord2(string s) {
        // 去掉最后的空格
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        // find 最后一个空格
        int last_space = s.find_last_of(' ');
        if (last_space == -1) {
            return s.size();
        }

        return s.size() - last_space - 1;
    }
};