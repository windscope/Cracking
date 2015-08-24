// Happy Number
// https://leetcode.com/problems/happy-number/

// O(N) memory complexity, O(1) time complecity : using an unordered_set;
// O(1) memory complexity, O(N) time complecity : using the two pointer algorithm that match the two
// set in one
#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> lookup_set;
        while (n != 1 && lookup_set.find(n) == lookup_set.end()) {
                lookup_set.insert(n);
                int prev = n;
                n = pow(prev % 10, 2);
                while (prev / 10 > 0) {
                    prev /= 10;
                    n += pow(prev % 10, 2);
                }
        }
        return n == 1;
    }

    int calculate_square_sum (int input) {
        int result = 0;
        do {
            result += pow(input % 10, 2);
            input /= 10;
        } while (input > 0);
        return result;
    }

    bool isHappy2(int n) {
        if (n == 1) {
            return true;
        }
        int fast_it = n;
        int slow_it = n;
        do {
            slow_it = calculate_square_sum(slow_it);
            fast_it = calculate_square_sum(calculate_square_sum(fast_it));
        } while(slow_it != 1 && slow_it != fast_it);
        return slow_it == 1;
    }
};

int main() {
    Solution s;
    vector<int> test_data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 324, 3423, 333};
    for (auto item : test_data) {
        assert(s.isHappy(item) == s.isHappy2(item));
    }
    cout << "You Passed" << endl;
    return 0;
}
