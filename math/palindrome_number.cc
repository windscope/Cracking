// https://leetcode.com/problems/palindrome-number
// Determine whether an integer is a palindrome. Do this without extra space.
// Algorith:
//          reverse the number and then compare
// lessons to learn:
//                  corner cases:
//                      1. Negative number shouldn't count as palindrome_number
//                      2. All numbers problem must check for the boundary in case it overflow
//                  We could stop at the middle and then compare the two number, n/2 time

// Score: 20ms

#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    bool isPalindrome(const int x) {
        if (x >= INT_MAX || x < 0) {
            return false;
        }
        int x_copy = x;
        int comparer = 0;
        int single_digit = 0;
        while (x_copy >= 10) {
            single_digit = x_copy % 10;
            x_copy /= 10;
            comparer = comparer * 10 + single_digit;
        }
        comparer = comparer * 10 + x_copy;
        return comparer == x;
    }

    bool isPalindrome2(const int x) {
        if (x >= INT_MAX || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int x_copy = x;
        int comparer = 0;
        while (x_copy > comparer) {
            comparer = comparer * 10 + x_copy % 10;
            x_copy /= 10;
        }
        return comparer == x_copy || comparer / 10 == x_copy;
    }
};


int main() {
    int correct[5] = {1, 12321, 123321, 1111, 12321};
    int incorrect[5] = {10, 123, -2147447412, 2147483647, 100};
    Solution s;
    for(uint32_t i = 0; i < 5; ++i) {
        assert(s.isPalindrome2(correct[i]));
        assert(!s.isPalindrome2(incorrect[i]));
    }
    cout << "You passed!" << endl;
    return 0;
}
