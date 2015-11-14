// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the word list
// For example,

// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
#include <climits>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(const string& beginWord, const string& endWord, unordered_set<string>& wordList) {
        if (beginWord.empty() || endWord.empty()) {
            return beginWord.size() == endWord.size();
        }
        int count = 2;
        if (isOneCharDiff(beginWord, endWord)) {
            return count;
        }
        queue<string> wordQ;
        wordQ.push(beginWord);
        if (wordList.count(beginWord) > 0) {
            wordList.erase(beginWord);
        }
        if (wordList.count(endWord) > 0) {
            wordList.erase(endWord);
        }
        while (!wordQ.empty()) {
            string cur = wordQ.front();
            wordQ.pop();
            count++;
            for (auto it = wordList.begin(); it != wordList.end(); ++it) {
                if (isOneCharDiff(*it, cur)) {
                    if (isOneCharDiff(*it, endWord)) {
                        return count;
                    } else {
                        wordQ.push(*it);
                        wordList.erase(it);
                    }
                }
            }
        }
        return INT_MAX;
    }
private:
    bool isOneCharDiff(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
            }
            if (diff > 1) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
    unordered_set<string> dict = {
        "hot",
        "got",
        "let",
        "bet",
        "cot",
        "lot",
        "mot",
        "tit"
    };
    unordered_set<string> dict2 = {
        "hot","cog","dot","dog","hit","lot","log"
    };
    Solution s;
    cout << "ladder: " << s.ladderLength("hot", "let", dict) << endl;
    cout << "ladder: " << s.ladderLength("hit", "cog", dict2) << endl;

    return 0;
}
