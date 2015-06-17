// From Leetcode, problem 15
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Note: 1. lements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//       2. The solution set must not contain duplicate triplets.

// Solve algorithm:
//  1. Sort O(N*log(n))
//  2. 2 pointer to loop through the array O(N^2)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

namespace crack {

typedef vector<int>::const_iterator const_vint;

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
        return result;
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        two_pointer_algorithm(nums[i], nums.begin() + i + 1, nums.end() - 1, &result);
    }
    return result;
}

void print_vector(const vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void print_result(const vector<vector<int>>& result) {
    for (auto it = result.begin(); it != result.end(); ++it) {
        print_vector(*it);
    }
}

private:
void two_pointer_algorithm(int value,
        const_vint begin,
        const_vint end,
        vector<vector<int>>* result) {
    while (begin < end) {
        if (value + *begin + *end == 0) {
            result->push_back({value, *begin, *end});
            while (begin < end && *begin == *(begin + 1)) {
                ++begin;
            }
            while (begin < end && *end == *(end - 1)) {
                --end;
            }
            ++begin;
            --end;
        } else if(value + *begin + *end > 0) {
            while (begin < end && *end == *(end - 1)) {
                --end;
            }
            --end;
        } else {
            while (begin < end && *begin == *(begin + 1)) {
                ++begin;
            }
            ++begin;
        }
    }
}

};
} // namespace crack

int main(void) {
    crack::Solution s;
    std::vector<int> data = {1, 1, 2, 0, -1, -2, -2};
    vector<vector<int>> result = s.threeSum(data);
    s.print_result(result);
    assert(result.size() == 3);
    cout << "You Passed" << endl;
    return 0;
}
