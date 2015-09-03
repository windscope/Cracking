// Sourece https://leetcode.com/problems/longest-palindromic-substring/

// Given a string S, find the longest palindromic substring in S. You may assume that the maximum
// length of S is 1000, and there exists one unique longest palindromic substring.

// Score: 40 ms
// Lession learnt:

// Alogrithm: dp, O(N^2)
//
#include <vector>
#include <string>

using std::string;

class Solution {
private:
    typedef std::vector<std::vector<bool>> D2vec_t;
public:
    string longestPalindrome(string s) {
        int max_len = 1;
        int longest_begin = 0;
        string result;
        if (s.empty()) return result;
        D2vec_t table(1000, std::vector<bool>(1000, false));
        // start from base class
        // first set all 1-1 true
        for (int i = 0; i < s.size(); ++i) {
            table[i][i] = true;
            longest_begin = i;
        }
        // then set all possible two pair to be true
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                longest_begin = i;
                max_len = 2;
            }
        }
        for (int len = 3; len <= s.size(); ++len) {
            int j = 0;
            for (int i = 0; i < s.size() - len + 1; ++i) {
                j = i + len - 1;
                if (s[i] = s[j] && table[i + 1][j - 1]) {
                    table[i][j] = true;
                    longest_begin = i;
                    max_len = len;
                }
            }
        }
        return s.substr(longest_begin, max_len);
    }
};

// middle out algorithm(quite similar to two pointer)
// the algorithm would consider the duplicates as one single point
class Solution {
public:
    string longestPalindrome(string s) {
        int min_index = 0;
        int max_len = 1;
        for (int i = 0; i < s.size(); ++i) {
            // break if the rest of the string can't compete with the existing anwser
            // a very clever optimization pattern
            if (s.size() - i <= max_len / 2) {
                break;
            }
            int k = i;
            int j = i;
            // skip the duplicates
            // skipping pattern
            while (k + 1 < s.size() && s[k] == s[k + 1]) {
                ++k;
            }
            // the next start must not be the duplicate char
            i = k;
            // expend from the middle
            while (k < s.size() - 1 && j > 0 && s[j - 1] == s[k + 1]) {
                --j;
                ++k;
            }
            int temp_len = k - j + 1;
            if (temp_len > max_len) {
                max_len = temp_len;
                min_index = j;
            }
        }
        return s.substr(min_index, max_len);
    }
};

int main() {
    return 0;
}
