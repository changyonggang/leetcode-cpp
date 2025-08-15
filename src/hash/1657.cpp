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

#include <string>

using namespace std;

// 两种操作: 1. 交换任意两个字符, a字符和b字符出现的位置交换   2. 将a字符出现的位置替换为b字符,b字符出现的位置替换为字符a

// 核心问题: 通过程序模拟转换过程,需要确定哪一步应该选择哪一种转化策略,贪心? 
// ~ 是不是可以按照相同子串的长度作为一种操作标准,当前选择一种可以使两个字符串的子串长度最长的方式转换.

// 操作hash表是最简单的方式
// 比较两个字符串对应的hash表,如果存在两个字符出现的次数交叉(在word1中a出现了1次,c出现了3次;在word2中a出现了3次,c出现了1次)
// 或者不同的两个字符出现了相同的次数(在word1中a出现了2次,在word2中b出现了2次)
class Solution1657 {
   public:
    bool closeStrings(string word1, string word2) {

    }
};