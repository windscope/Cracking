// Author: windscope <windscope@gmail.com>
// Given a array and a int s , find the minimum sub array that satisfy the sum of the subarray is greater than or equal to the given s. 
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        deque<int> array_deque;
        int sum = 0;
        size_t min_array_size = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > s) {
                return 1;
            } else if (sum + nums[i] <= s) {
                sum += nums[i];
                array_deque.push_back(nums[i]);
                ++min_array_size;
            } else {
                sum += nums[i];
                array_deque.push_back(nums[i]);
                while (sum - array_deque.front() >= s) {
                    sum -= array_deque.front();
                    array_deque.pop_front();
                    min_array_size = min(min_array_size, array_deque.size());
                }
            }
        }
    if (s > sum)
        return 0;
    else
        return min_array_size;
    }

    int minSubArrayLen2(int s, vector<int>& nums) {
        int min_array_size = 0;
        int sum = 0;
        int front = 0;
        int back = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            // one single int is greater than
            if (nums[i] >= s) {
                return 1;
            } else if (sum + nums[i] <= s) {
                sum += nums[i];
                front = i;
                ++min_array_size;
            } else {
                sum += nums[i];
                front = i;
                while (sum - nums[back] >= s && front - back >= 0) {
                    sum -= nums[back];
                    back++;
                    min_array_size = min(front - back + 1, min_array_size);
                }
            }
        }
    // if at the end, sum is less than s, return 0
        if(sum < s)
            return 0;
        else
            return min_array_size;
    }
};

int main(void) {
    Solution s;
    std::vector<int> data = {2,3,1,1,1,1,1};
    cout << s.minSubArrayLen2(5, data) << endl;
}
