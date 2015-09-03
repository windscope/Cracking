// Container With Most Water
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate
// (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the
// most water.

// Note: You may not slant the container.
// 2 pointer algorithm

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        // assign the min_index pointer to the lower hegiht of low and high
        int* min_index = height[low] < height[high] ? &low : &high;
        int max_area = (high - low) * height[*min_index];
        // from the min_index pointer, move to the other side, check whether to switch the min_index_ptr
        // while iterating, check the area under the curve, if greater than prevous, update
        while (high > low) {
            if (low == *min_index) {
                low++;
                if (height[low] > height[high]) {
                    min_index = &high;
                }
            } else {
                high--;
                if (height[high] > height[low]) {
                    min_index = &low;
                }
            }
            int temp_area = (high - low) * height[*min_index];
            if (temp_area > max_area) {
                max_area = temp_area;
            }
        }
        return max_area;
    }
};
