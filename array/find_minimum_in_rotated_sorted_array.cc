// Find Minimum in Rotated Sorted Array
// algorithm: bfs

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(high > low + 1) {
            if ( nums[high] > nums[low]) {
                return nums[low];
            } else {
                int mid = (high + low) / 2;
                if (nums[mid] > nums[low]) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
        }
        return min(nums[high], nums[low]);
    }
};

int main() {
    vector<vector<int>> datas = {
        {1, 2, 3, 4, 5, 0},
        {5, 6, 7, 2, 3, 4},
        {1},
        {1, 2}
    };
    vector<int> expected_result = {0, 2, 1, 1};
    Solution s;
    int count  = 0;
    for (auto data : datas) {
        assert(s.findMin(data) == expected_result[count++]);
    }
    cout << "You Passed!" << endl;
    return 0;
}
