#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        unordered_map<string, int> dict;
        vector<string> result;
        unordered_set<string> temp_results0;
        addHelper(num, dict, temp_results0);
        result.reserve(dict.size());
        for (const auto& pair : dict) {
            if (pair.second == target) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
private:
    void addHelper(
            const string& num,
            unordered_map<string, int>& dict,
            unordered_set<string>& multies) {

        if (num.empty()) {
            return;
        }
        if ((num.front() != '0' || num.size() == 1) && num.size() < 10 && stol(num) < INT_MAX) {
            dict[num] = stoi(num);
            multies.insert(num);
        }
        for (int i = 0; i < num.size() - 1; ++i) {
            unordered_map<string, int> left_dict;
            unordered_map<string, int> right_dict;
            string left = num.substr(0, i + 1);
            string right = num.substr(i + 1, num.size() - i - 1);
            unordered_set<string> left_multies;
            unordered_set<string> right_multies;
            addHelper(left, left_dict, left_multies);
            addHelper(right, right_dict, right_multies);
            for (const auto& l : left_dict) {
                for (const auto& r : right_dict) {
                    dict[l.first + "+" + r.first] = l.second + r.second;
                }
            }
            for (const auto& l : left_dict) {
                for (const auto& r : right_multies) {
                    dict[l.first + "-" + r] = l.second - right_dict[r];
                }
            }
            for (const auto& l : left_multies) {
                for (const auto& r : right_multies) {
                    int64_t temp = left_dict[l] * right_dict[r];
                    if (temp < INT_MAX) {
                        multies.insert(l + "*" + r);
                        dict[l + "*" + r] = left_dict[l] * right_dict[r];
                    }
                }
            }
        }
    }


};



void print_str_vector(const vector<string>& expressions) {
    cout << "[";
    for (const auto& expression : expressions) {
        cout << expression << ", ";
    }
    cout << "]" << endl;
}

int main(void) {
    vector<string> test_data = {
        "123",
        "232",
        "105",
        "00",
        "3456237490",
    };
    vector<int> test_target = {
        6,
        8,
        5,
        0,
        9191
    };
    vector<vector<string>> expected_result = {
        {"1+2+3", "1*2*3"},
        {"2*3+2", "2+3*2"},
        {"1*0+5","10-5"},
        {"0+0", "0-0", "0*0"},
        {}
    };

    Solution s;
    for (int i = 0; i < test_data.size(); ++i) {
        vector<string> result = s.addOperators(test_data[i], test_target[i]);
        cout << "result: ";
        print_str_vector(result);
        cout << "expected: ";
        print_str_vector(expected_result[i]);
    }
    return 0;
}
