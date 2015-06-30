// Sourece /longest-substring-without-repeating-characters/

// Given a string, find the length of the longest substring without repeating characters. For example,
// the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// For "bbbbb" the longest substring is "b", with the length of 1.

// Score: 40 ms
// Lession learnt: too simple

// Alogrithm:
//     2 pointers, 2 pointers

#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start_point = 0;
        int max_size = 0;
        unordered_map<char, int> _lookup_map;
        for (int i = 0; i < s.size(); ++i) {
            if (_lookup_map.find(s[i]) == _lookup_map.end()) {
                _lookup_map[s[i]] = i;
            } else {
                if (start_point <= _lookup_map[s[i]]) {
                    start_point = _lookup_map[s[i]] + 1;
                }
                _lookup_map[s[i]] = i;
            }
            max_size = max(max_size, i - start_point + 1);
        }
        return max_size;
    }
};

int main() {
    string data1 = "a";
    string data2 = "";
    string data3 = "abcabcd";
    string data4 = "abaad";

    Solution s;

    assert(1 == s.lengthOfLongestSubstring(data1));
    assert(0 == s.lengthOfLongestSubstring(data2));
    assert(4 == s.lengthOfLongestSubstring(data3));
    assert(2 == s.lengthOfLongestSubstring(data4));
    cout << "pass" << endl;

    return 0;
}
