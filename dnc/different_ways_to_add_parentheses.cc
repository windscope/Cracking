// Different Ways to Add Parentheses
// https://leetcode.com/problems/different-ways-to-add-parentheses/
// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
// Example 1
// Input: "2-1-1".
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]

// Example 2
// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    static const char PLUS = '+';
    static const char MINUS = '-';
    static const char MULTIPLY = '*';

    typedef vector<int>::iterator vint_iter_t;
    typedef vector<char>::iterator vchar_iter_t;
    typedef pair<vint_iter_t, vint_iter_t> vint_iter_pair_t;
    typedef pair<vchar_iter_t, vchar_iter_t> vchar_iter_pair_t;

    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        vector<int> results;
        int str_start = 0;
        int str_len = 0;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == PLUS || input[i] == MINUS || input[i] == MULTIPLY) {
                nums.push_back(stoi(input.substr(str_start, str_len)));
                ops.push_back(input[i]);
                str_start = i + 1;
                str_len = 0;
            } else {
                str_len++;
            }
        }
        nums.push_back(stoi(input.substr(str_start, str_len)));
        results = divider(
                make_pair(nums.begin(), nums.end()),
                make_pair(ops.begin(), ops.end())
            );
        sort(results.begin(), results.end());
        return results;

    }

    vector<int> conquer(vint_iter_pair_t left_nums,
                vint_iter_pair_t right_nums,
                vchar_iter_pair_t left_ops,
                vchar_iter_pair_t right_ops,
                const char op) {
        // base conditions
        if (left_nums.first + 1 == left_nums.second && right_nums.first + 1 == right_nums.second) {
            return {calculate(*left_nums.first, *right_nums.first, op)};
        }
        vector<int> left_results = divider(left_nums, left_ops);
        vector<int> right_results = divider(right_nums, right_ops);
        vector<int> result;
        for (auto l : left_results) {
            for (auto r : right_results) {
                result.push_back(calculate(l, r, op));
            }
        }
        return result;
    }

    vector<int> divider(vint_iter_pair_t nums, vchar_iter_pair_t ops) {
        if (nums.first + 1 == nums.second) {
            return {*nums.first};
        }
        vector<int> result;
        int i = 0;
        for (auto it = ops.first; it < ops.second; ++it, ++i) {
            vector<int> temp = conquer(
                    make_pair(nums.first, nums.first + i + 1),
                    make_pair(nums.first + i + 1, nums.second),
                    make_pair(ops.first, ops.first + i),
                    make_pair(ops.first + i + 1, ops.second),
                    *(ops.first + i)
                );
            concatenate_vectors(temp, result);
        }
        return result;
    }

    int calculate(const int a, const int b, const char op) {
        if (op == PLUS) {
            return a + b;
        } else if (op  == MINUS) {
            return a - b;
        } else if (op == MULTIPLY) {
            return a * b;
        } else {
            // un-accessable
            assert(false);
        }
    }

     void concatenate_vectors(const vector<int>& from, vector<int>& to) {
        to.reserve(to.size() + from.size());
        to.insert(to.end(), from.begin(), from.end());
     }

};

int main() {
    string data = "2*3-4*5";
    cout << data << endl;
    Solution s;
    vector<int> results = s.diffWaysToCompute(data);
    for (auto result : results) {
        cout << result << ", ";
    }
    cout << endl;
    return 0;
}
