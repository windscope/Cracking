#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            findMedianSortedArrays(nums2, nums1);
        }
    }

    double find_median_sorted_array(vector<int>& nums1, vector<int>& nums2, int nums1_front, int nums1_tail, int nums2_front, int nums2_tail) {
        int nums1_index = (nums1_front + nums1_tail) / 2;
        int nums2_index = (nums2_front + nums2_tail) / 2;
        if (nums1[nums1_index] == nums2[nums2_index]) {
            return static_cast<double> nums2[nums2_index];  
        } else if (abs(nums1[nums1_index] - nums2[nums2_index]) == 1) {
            return (nums1[nums1_index] + nums2[nums2_index]) / 2; 
        } else if (nums1[nums1_index] > nums2[nums2_index]) {
            return find_median_sorted_array(nums1, nums2, nums1)
        } else if ()
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
    vector<int> tests = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3},
        {},
        {4, 4, 4, 4, 4}, 
        {0,  0, 0, 0},
        {4, 5, 6, 10}
    }

    Solution s;
    
    for (int i = 0; i < tests.size(); ++i) {
        for (int j = 0; j < tests.size(); ++j) {
            assert(s.findMedianSortedArrays(tests[i], tests[j]) == s.findMedianSortedArrays(tests[i], tests[j]));
        }
    }
    return 0;
}