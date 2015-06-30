// Sourece https://leetcode.com/problems/foursum

/* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d =
 * target? Find all unique quadruplets in the array which gives the sum of target.
 *  1. Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *  2. The solution set must not contain duplicate quadruplets.
 */

// Score: 16ms
// Lession learnt:
//
// Alogrithm:
//     first get a combinition
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
typedef vector<int>::const_iterator cvint_it_t;

public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
        return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() -3; ++i) {
        if (i >0 && nums[i-1] == nums[i]) {
            continue;
        } else {
            three_sum(nums.begin() + i + 1, nums.end() - 1, nums[i], target - nums[i], &result);
        }
    }
    return result;
}

private:
void three_sum(
        cvint_it_t begin,
        cvint_it_t end,
        const int four_sum_pointer,
        const int target,
        vector<vector<int>>* result) {
    cvint_it_t starter = begin;
    while(begin < end) {
        while (begin > starter && *begin == *(begin - 1)) {
            ++begin;
        }
        two_sum(begin + 1, end, four_sum_pointer, *begin, target - *begin, result);
        ++begin;
    }
}

void two_sum(
        cvint_it_t begin,
        cvint_it_t end,
        const int four_sum_pointer,
        const int three_sum_pointer,
        const int target,
        vector<vector<int>>* result) {
    while(begin < end) {
        if (*begin > 0 && *begin > target) {
            return;
        }
        if (*begin + *end == target) {
            result->push_back({four_sum_pointer, three_sum_pointer, *begin, *end});
            while (begin < end && *begin == *(begin + 1)) {
                ++begin;
            }
            while (begin < end && *end == *(end - 1)) {
                --end;
            }
            ++begin;
            --end;
        } else if (*begin + *end > target) {
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

int main() {
    vector<int> data = {1, 0, 0, -1, 0, -2, 2};
    vector<int> data2 = {-1, 0, -5, -2, -2, -4, 0, 1, -2};
    Solution s;
    vector<vector<int>> result = s.fourSum(data, 0);
    vector<vector<int>> result2 = s.fourSum(data2, -9);
    assert(result.size() == 3);
    assert(result2.size() == 4);
    cout << "You passed!" << endl;
    return 0;
}
