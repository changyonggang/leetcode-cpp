#include <iostream>

using namespace std;

class Solution1768 {
   public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        size_t len1 = word1.size();
        size_t len2 = word2.size();
        size_t idx1 = 0, idx2 = 0;

        merged.reserve(len1 + len2);

        while (idx1 < len1 || idx2 < len2) {
            if (idx1 < len1 && idx2 < len2) {
                merged += word1[idx1];
                idx1++;
                merged += word2[idx2];
                idx2++;
            } else if (idx1 < len1) {
                merged += word1[idx1];
                idx1++;
            } else {
                merged += word2[idx2];
                idx2++;
            }
        }

        return merged;
    }
};
