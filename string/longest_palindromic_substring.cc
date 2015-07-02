// Sourece https://leetcode.com/problems/longest-palindromic-substring/

// Given a string S, find the longest palindromic substring in S. You may assume that the maximum
// length of S is 1000, and there exists one unique longest palindromic substring.

// Score: 40 ms
// Lession learnt:

// Alogrithm:
// Stack
#include <vector>
#include <string>

using std::string;

class Solution {
private:
    typedef std::vector<std::vector<bool>> D2vec_t;
public:
    string longestPalindrome(string s) {
        D2vec_t table(1000, std::vector<bool>(1000, false));
    }
};

int main() {
    return 0;
}
