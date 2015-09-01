// https://leetcode.com/problems/longest-common-prefix/
// Write a function to find the longest common prefix string amongst an array of strings.

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
