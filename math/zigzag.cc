// https://leetcode.com/problems/zigzag-conversion/
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R

#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1 || s.size() == 1 || s.size() <= numRows) {
            return s;
        }
        string ret;
        int base = numRows - 1;
        for (int i = 0; i < numRows; ++i) {
            int odd_step, even_step;
            if (i == 0 || i == numRows - 1) {
                odd_step = even_step = 2 * base;
            } else {
                odd_step = (base - i) * 2;
                even_step = i * 2;
            }
            int step = 0;
            int pos = i;
            int count = 0;
            while (pos + step < s.size()) {
                ++count;
                pos += step;
                ret.push_back(s[pos]);
                step = (count % 2 == 1 ? odd_step : even_step);
            }
        }
        return ret;
    }
};


int main() {
    string data = "A";
    Solution s;
    string ret = s.convert(data, 1);
    assert(ret.compare("A") == 0);
    cout << "pass" << endl;
}
