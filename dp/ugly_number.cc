// Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/
// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note that 1 is typically treated as an ugly number.

#include <cassert>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // two is 0, three is 1, five is 2
        vector<int> ptrs = {0, 0, 0};
        vector<int> products = {0, 0, 0};
        const vector<int> CONSTANTS = {2, 3, 5};
        vector<int> ugly_sequence = {1};
        for (int i = 0; i < n - 1; ++i) {
            for (int i = 0; i < ptrs.size(); ++i) {
                products[i] = ugly_sequence[ptrs[i]] * CONSTANTS[i];
            }
            int min = find_min(products);
            ugly_sequence.push_back(min);
            for (int i = 0; i < ptrs.size(); ++i) {
                if (min == products[i]) {
                    ptrs[i]++;
                }
            }
        }
        return *ugly_sequence.rbegin();
    }

    int find_min(const vector<int>& sequence) {
        int min = INT_MAX;
        for (auto item : sequence) {
            if (item < min) {
                min = item;
            }
        }
        return min;
    }
};

int main() {
    return 0;
}
