// Next Permutation
// https://leetcode.com/problems/next-permutation/

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) {
            return ;
        }
        auto it = nums.rbegin();
        auto swapper = nums.rend();
        for (; it < nums.rend(); ++it) {
            if (it != nums.rbegin()  && *it < *(it - 1)) {
                swapper = it;
                break;
            }
        }
        if (swapper == nums.rend()) {
            std::reverse(nums.rbegin(), nums.rend());
            return;
        }
        auto swappee = nums.rend();
        int min_diff = INT_MAX;
        for (auto iter = nums.rbegin(); iter < swapper; ++iter) {
            int diff = *iter - *swapper;
            if (diff > 0 && diff < min_diff) {
                min_diff = diff;
                swappee = iter;
            }
        }
        // cout << "swapper: " << *swapper << ", swappee: " << *swappee << endl;
        // swap
        int temp = *swapper;
        *swapper = *swappee;
        *swappee = temp;

        // reverse the afters of swapper
        // cout << "reversed: " << *nums.rbegin() << ", " << *(swapper - 1) << endl;
        reverse(nums.rbegin(), swapper);
    }

    // void reverse(vector<int>::reverse_iterator first, vector<int>::reverse_iterator last) {
    //     while((first < last)) {
    //         int temp = *first;
    //         *first = *last;
    //         *last = temp;
    //         first++;
    //         last--;
    //     }
    // }
};

int main() {
    vector<int> test_data = {3, 2, 1, 4};
    Solution s;
    for (int i = 0; i < 10; ++i) {
        s.nextPermutation(test_data);
        for (auto item : test_data) {
            cout << item << ", ";
        }
        cout << endl;
    }
    return 0;
}
