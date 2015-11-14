#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        // signs record the predefine sign: signs*1()
        signs.push(1);
        // treat a as (a)
        int sign = 1;
        int accum = 0;
        int num = 0;

        s.push_back(')');
        for (auto c : s) {
            if (c == '+' || c == '-') {
                accum += num * sign * signs.top();
                sign = c == '+' ? 1 : -1;
                num = 0;
            } else if (c == '(') {
                // flip signs if neccesary
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                // calcuate the result if necessary
                accum += num * sign * signs.top();
                signs.pop();
                sign = 1;
                num = 0;
            } else if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == ' ') {
                continue;
            } else {
                // unreachable
                return 0;
            }
        }
        return accum;
    }
};

int main() {
    vector<string> test_cases = {
        "0",
        "10",
        "5+2-3",
        "8-(3+5)+(3+2)",
        "(10)+2",
        "1-(100+3-2+4-3)",
        "10+32-(3+2-4+44-33)+(22+3-21+3)-(3232+333-222)+3-32-21-2",
        "  30",
        "(3-(2-(5-(9-(4)))))"
    };

    vector<int> results = {
        0,
        10,
        4,
        5,
        12,
        -101,
        -3358,
        30,
        1
    };

    Solution s;
    for (int i = 0; i < static_cast<int>(test_cases.size()); ++i) {
        // cout << "calculated: " << s.calculate(test_cases[i]) << ", real: " <<results[i] << endl;
        assert(s.calculate(test_cases[i]) == results[i]);
    }
    cout << "You Passed" << endl;
    return 0;

}
