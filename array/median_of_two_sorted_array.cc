//
//
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    typedef vector<int>::const_iterator cvint_t;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        pair<int, int> compare_pair;
        if (nums1.empty()) {
            return find_median_sorted_array(nums2.begin(), nums2.end(), &compare_pair);
        }
        if (nums2.empty()) {
            return find_median_sorted_array(nums2.begin(), nums2.end(), &compare_pair);
        }
        vector<int> shift(4, 0);
        double median1 = find_median_sorted_array(nums1.begin() + shift[0], nums1.end() - shift[1]);
        double median2 = find_median_sorted_array(nums2.begin() + shift[2], nums2.end() - shift[3]);
        while (median1 - median2){}
    }

    double find_median_sorted_array(cvint_t begin, cvint_t end, pair<int, int>* compare_pair) {

        int dist = distance(begin, end);
        int index = dist / 2;
        double median = 0;
        if (dist%2 == 0) {
            compare_pair->first = *(begin + index);
            compare_pair->second = *(begin + index + 1);
            median = reinterpret_cast<double>(compare_pair->first) / compare_pair->second;
        } else {
            median = *(begin + index);
            compare_pair->fisrt = *(begin + index - 1);
            compare_pair->second = *(begin + index + 1);
        }
        return median;
    }

};
