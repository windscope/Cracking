// https://leetcode.com/problems/integer-to-roman/
// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

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
        roman_map[1] = "I";
        roman_map[4] = "IV";
        roman_map[5] = "V";
        roman_map[9] = "IX";
        roman_map[10] = "X";
        roman_map[40] = "XL";
        roman_map[50] = "L";
        roman_map[90] = "XC";
        roman_map[100] = "C";
        roman_map[400] = "CD";
        roman_map[500] = "D";
        roman_map[900] = "CM";
        roman_map[1000] = "M";
        roman_vect = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    }

    string intToRoman_iterative(const int num) {
        int data = num;
        string ret = "";
        for (auto roman : roman_vect) {
            while (data >= roman) {
                ret += roman_map[roman];
                data -= roman;
            }
        }
        return ret;
    }
    string intToRoman_recursive(const int num) {
        for (auto roman : roman_vect) {
            if (num >= roman) {
                return roman_map[roman] + intToRoman_recursive(num - roman);
            }
        }
        return "";
    }
private:
    unordered_map<int, string> roman_map;
    vector<int> roman_vect;
};

int main() {
    Solution s;
    vector<string> ret_data = {"IX","VI", "III", "XVI", "XIV"};
    vector<int> data = {9, 6, 3, 16, 14};
    for (int i = 0; i < data.size(); ++i) {
        assert(ret_data[i] == s.intToRoman_recursive(data[i]));
        // cout << s.intToRoman(data[i]) << endl;
    }
    cout << "You Passed!" << endl;
    return 0;
}
