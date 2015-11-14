#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int sum_size = nums1.size() + nums2.size();
        return (find_kth_wrapper(nums1, nums2, (sum_size + 1) / 2) + find_kth_wrapper(nums1, nums2, (sum_size + 2) / 2)) / 2.0;
    }

    int find_kth_wrapper(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k > nums1.size() + nums2.size()) {
            return -1;
        }
        return find_kth(nums1, nums2, 0, static_cast<int>(nums1.size()), 0, static_cast<int>(nums2.size()), k);
    }

    int find_kth(vector<int>& nums1,
            vector<int>& nums2,
            int nums1_front,
            int nums1_len,
            int nums2_front,
            int nums2_len,
            int k
        ) {
        int i = static_cast<int>(static_cast<double>(nums1_len) / (nums1_len + nums2_len) * (k - 1));
        int j = k - 1 - i;
        // cout << "i: " << i << ",j: " << j << ",nums1_front" << nums1_front << ",nums2_front: " << nums2_front << ",nums1_len: " << nums1_len << ",nums2_len: " << nums2_len << endl;
        int nums1_1i = ((i == 0) ? INT_MIN : nums1[nums1_front + i - 1]);
        int nums2_1j = ((j == 0) ? INT_MIN : nums2[nums2_front + j - 1]);
        int nums1_i = (i == nums1_len) ? INT_MAX : nums1[nums1_front + i];
        int nums2_j = (j == nums2_len) ? INT_MAX : nums2[nums2_front + j];
        // cout << "nums1_1i: " << nums1_1i << ", nums1_i: " << nums1_i << ", nums2_1j:" << nums2_1j << ", nums2_j: " << nums2_j << endl;
        if (nums2_1j <= nums1_i && nums1_i <= nums2_j) {
            return nums1_i;
        }
        if (nums1_1i <= nums2_j && nums2_j <= nums1_i) {
            return nums2_j;
        }

        if (nums1_i > nums2_j) {
            return find_kth(nums1, nums2, nums1_front, i, nums2_front + j + 1, nums2_len - j - 1, k - j - 1);
        } else {
            return find_kth(nums1, nums2, nums1_front + i + 1, nums1_len - i - 1, nums2_front, j, k - i - 1);
        }
    }
};

































double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);   // Make sure A2 is the shorter one.

    if (N2 == 0) return ((double)nums1[(N1-1)/2] + (double)nums1[N1/2])/2;  // If A2 is empty

    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];  // Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

        if (L1 > R2) lo = mid2 + 1;     // A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;    // A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2; // Otherwise, that's the right cut.
    }
    return -1;
}

int main() {
    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3},
        {},
        {4, 4, 4, 4, 4},
        {0,  0, 0, 0},
        {4, 5, 6, 10}
    };

    Solution s;

    for (int i = 0; i < tests.size(); ++i) {
        for (int j = 0; j < tests.size(); ++j) {
            if (i == j && i == 2) continue;
            assert(findMedianSortedArrays(tests[i], tests[j]) == s.findMedianSortedArrays(tests[i], tests[j]));
        }
    }
    cout << "HELLO WOLRD" << endl;
    return 0;
}
