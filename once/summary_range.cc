// https://leetcode.com/problems/summary-ranges/

// Given a sorted integer array without duplicates, return the summary of its ranges.
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<string> ret;
        ostringstream sout;
        int first = 0;
        int last = 0;
        string s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i - 1] + 1 < nums[i]) {
                s = get_str(nums, first, i - 1, sout);
                first = i;
                ret.push_back(s);
            }
        }
        s = get_str(nums, first, nums.size() - 1, sout);
        ret.push_back(s);
        return ret;
    }

    string get_str(const vector<int>& nums, const int first, const int last, ostringstream& sout) {
        if (first == last) {
            sout << nums[first];
        } else {
            sout << nums[first] << "->" << nums[last];
        }
        string ret = sout.str();
        sout.str(std::string());
        sout.clear();
        return ret;
    }
};
void print_vect(const vector<string>& data) {
    for (auto it : data) {
        cout << it << ", ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> data = {1, 2, 3, 4, 10, 11, 12, 13, 22, 33};
    vector<string> ret = s.summaryRanges(data);
    print_vect(ret);
    return 0;
}
