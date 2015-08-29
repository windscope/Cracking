// https://leetcode.com/problems/roman-to-integer/
// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.
// any of the letters representing numbers in the Roman numerical system: I = 1, V = 5, X = 10,
// L = 50,C = 100,D = 500, M = 1,000. In this system, a letter placed after another of greater value
// adds (thus XVI or xvi is 16), whereas a letter placed before another of greater value subtracts
// (thus XC or xc is 90).

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    Solution() {
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
    }

    int romanToInt(string s) {
        int ret = 0;
        for (uint32_t i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
                ret -= roman_map[s[i]];
            } else {
                ret += roman_map[s[i]];
            }
        }
        return ret;
    }
private:
    unordered_map<char, int> roman_map;
};

int main() {
    Solution s;
    vector<string> data = {"IX","VI", "III", "XVI", "XIV"};
    vector<int> ret_data = {9, 6, 3, 16, 14};
    for (int i = 0; i < data.size(); ++i) {
        assert(ret_data[i] == s.romanToInt(data[i]));
    }
    cout << "You Passed!" << endl;
    return 0;
}
