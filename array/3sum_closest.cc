// Sourece https://leetcode.com/problems/3sum-closest

/* Problem: Given an array S of n integers, find three integers in S such that the sum is closest
 * to a given number, target. Return the sum of the three integers. You may assume that each input
 * would have exactly one solution.
 */

// Score: 16ms
// Lession learnt:
//     No optimization at first, an unthoughtful optimization may leads to a bug.
// Alogrithm:
//     Similar to 3 sum problem in leetcode, first sort, then use 2 pointer to iterate the loop.
#include <algorithm>
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
typedef vector<int>::const_iterator cvint_it;
public:
int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2];
    int diff = INT_MAX;
    if (nums.size() < 3) {
        return ret;
    }
    for (int i = 0; i < nums.size() - 2; ++i) {
        cout << "i is" << i << endl;
        if (nums[i] > 0 && nums[i] >= target) {
            cout << "here in 1" << endl;
            return ret;
        }
        if (i > 0 && nums[i-1] == nums[i]) {
            continue;
        }
        two_pointer_algorithm(target, nums[i], nums.begin() + i + 1, nums.end() - 1, &ret, &diff);
        if (diff == 0) {
            cout << "here in 2" << endl;
            return ret;
        }
    }
    cout << "diff is " << diff << endl;
    cout << "ret is " << ret << endl;
    // unreachable
    return ret;
}

void two_pointer_algorithm(
        const int target,
        const int value,
        cvint_it begin,
        cvint_it end,
        int* ret,
        int* diff) {
    while (begin < end) {
        int local_sum = value + *begin + *end;
        int local_diff = local_sum - target;
        if (local_diff == 0) {
            *diff = 0;
            *ret = target;
            return;
        } else if (local_diff > 0) {
            update_ret_and_diff_if_possible(local_diff, local_sum, ret, diff);
            // optimizattion, skip the duplicated nums
            while (begin < end && *end == *(end -1)) {
                --end;
            }
            --end;
        } else if (local_diff < 0) {
            update_ret_and_diff_if_possible(local_diff, local_sum, ret, diff);
            while (begin < end && *begin == *(begin + 1)) {
                ++begin;
            }
            ++begin;
        }
    }
}
void update_ret_and_diff_if_possible(
    const int local_diff,
    const int local_sum,
    int* ret,
    int* diff) {
    if(abs(local_diff) < *diff) {
        *diff = abs(local_diff);
        *ret = local_sum;
    }
}
};

int main() {
    vector<int> data = {2, -1, 7, 9, 5, 3, 1, 23, 9, 7};
    vector<int> data2 = {1, 1, 1, 0};
    vector<int> data3 = {-3, -2, -5, 3, -4};
    vector<int> data4 = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,
            -18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,
            14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,
            14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10};
    const int target1 = 6;
    const int target2 = 50;
    const int target3 = -9;
    const int target4 = 3;
    const int target5 = -1;
    const int target6 = -52;
    Solution s;
    assert(target1 == s.threeSumClosest(data, target1));
    assert(41 == s.threeSumClosest(data, target2));
    assert(2 == s.threeSumClosest(data, target3));
    assert(3 == s.threeSumClosest(data2, target4));
    assert(-2 == s.threeSumClosest(data3, target5));
    assert(target6 == s.threeSumClosest(data4, target6));
    cout << "You Passed!" << endl;
    return 0;
}
