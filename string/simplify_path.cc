// https://leetcode.com/problems/simplify-path/
// Simplify Path Total Accepted: 35346 Total Submissions: 175912 My Submissions Question Solution
// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// click to show corner cases.

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/
// In this case, you should ignore redundant slashes and return "/home/foo".
#include <stack>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
    static const char slash = '/';
    static const char dot = '.';

public:
    string simplifyPath(string path) {
        stack<string> path_stack;
        int starter = 0;
        int len = 0;
        int len_sum = 0;
        int dot_count = 0;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == dot) {
                ++dot_count;
            } else if (path[i] == slash) {
                if (len == 0 && dot_count != 0) {
                    if (dot_count == 2 && !path_stack.empty()){
                        path_stack.pop();
                    } else if (dot_count > 2){
                        path_stack.push(string(path.begin() + starter, path.begin() + i));
                    }
                    dot_count = 0;
                } else if (len != 0) {
                    path_stack.push(string(path.begin() + starter, path.begin() + i));
                    len_sum += len;
                    len = 0;
                }
                starter = i + 1;
                dot_count = 0;
            } else {
                ++len;
            }
        }
        if (len != 0 || dot_count == 0 || dot_count > 2) {
            path_stack.push(string(path.begin() + starter, path.end()));
        } else if (dot_count == 2) {
            if (path_stack.empty()) {
                return "/";
            } else {
                path_stack.pop();
            }
        }
        if (path_stack.empty()) {
            return "/";
        }
        string ret;
        ret.reserve(len_sum + path_stack.size());
        while (!path_stack.empty()) {
            string temp = "/" + path_stack.top();
            path_stack.pop();
            ret = temp + ret;
        }
        if (ret.size() > 1 && ret[ret.size()-1] == slash) {
            ret.pop_back();
        }
        return ret;
    }
};

class Solution2 {
public:
    static const char slash = '/';

    string simplifyPath(string path) {
        stringstream ss(path);
        string ret, temp;
        vector<string> paths;
        while (getline(ss, temp, slash)) {
            if (temp == "." || temp == "") continue;
            if (temp == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else {
                paths.push_back(temp);
            }
        }
        if (paths.empty()) return "/";
        for (const auto& p : paths) {
            ret += "/" + p;
        }
        return ret;
    }
};

int main() {
    vector<string> datas = {
        "/home",
        "///home",
        "/a/b///c//d",
        "/a/../b/c",
        "/../a/b/c",
        "/../",
        "/a/b/c/..",
        "/..",
        "/.",
        "/...",
        "/.../a/../b/.",
        "/.../",
        "/..hidden",
        "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///"
    };
    vector<string> expected_result = {
        "/home",
        "/home",
        "/a/b/c/d",
        "/b/c",
        "/a/b/c",
        "/",
        "/a/b",
        "/",
        "/",
        "/...",
        "/.../b",
        "/...",
        "/..hidden",
        "/e/f/g"
    };
    Solution2 s;
    for (int i = 0; i < datas.size(); ++i) {
        // cout << "expected: " << expected_result[i] << endl;
        // cout << "reality: " << s.simplifyPath(datas[i]) << endl;
        assert(s.simplifyPath(datas[i]) == expected_result[i]);
    }
    cout << "You Passed" << endl;
    return 0;
}
