#include <vector>

using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;  // 写指针
        int read = 0;   // 读指针

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // 统计相同字符数量
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // 写入当前字符
            chars[write++] = currentChar;

            // 写入计数（如果大于1）
            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
