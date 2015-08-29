// Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space.

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // remove all the noisy spaces
        while (*(s.end() - 1) == ' ') {
            s.erase(s.end() - 1);
        }
        while (*s.begin() == ' ') {
            s.erase(s.begin());
        }
        for (auto it = s.begin(); it < s.end(); ++it) {
            if (*it == ' ') {
                if (it > s.begin() && it < s.end() + 1) {
                    if (*(it + 1) != ' ' && *(it - 1) != ' ') {
                        continue;
                    }
                }
                s.erase(it);
            }
        }
        // reverse the whole string
        reverse(s.begin(), s.end());

        string::iterator start = s.begin();
        string::iterator finish = s.begin();
        // reverse all character in each word
        for (auto it = s.begin(); it < s.end(); ++it, ++finish) {
            if (*it == ' ') {
                reverse(start, finish);
                start = finish + 1;
            }
        }
        reverse(start, finish);
    }
};

int main() {
    string data1 = "       ";
    string data2 = "  Hello  world  :) template          ";
    Solution s;
    s.reverseWords(data1);
    s.reverseWords(data2);
    cout << "{" << data1 << "}" << endl;
    cout << "{" << data2 << "}" << endl;
    return 0;
}
