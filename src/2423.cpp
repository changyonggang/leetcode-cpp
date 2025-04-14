#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool equalFrequency(string word) {
    unordered_map<char, int> freq;
    for (char ch : word) {
        freq[ch]++;
    }

    for (int i = 0; i < word.size(); i++) {
        unordered_map<char, int> tempFreq = freq;
        tempFreq[word[i]]--;
        if (tempFreq[word[i]] == 0) {
            tempFreq.erase(word[i]);
        }

        unordered_set<int> freqSet;
        for (auto& [ch, count] : tempFreq) {
            freqSet.insert(count);
        }

        if (freqSet.size() == 1) {
            return true;
        }
    }

    return false;
}
