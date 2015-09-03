// Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/
// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <vector>
#include <iostream>

using namespace std;

// next time rewrite

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return divider(1, n);
    }

    vector<TreeNode*> divider(const int starter, const int ender) {
        if (starter > ender) {
            return {nullptr};
        } else if (starter == ender) {
            return {new TreeNode(starter)};
        }
        vector<TreeNode*> ret;
        for (int i = starter - 1; i < ender; ++i) {
            vector<TreeNode*> temp_left = divider(starter, i);
            vector<TreeNode*> temp_right = divider(i + 2, ender);
            vector<TreeNode*> temp_result = combiner(temp_left, i + 1, temp_right);
            ret.insert(ret.end(), temp_result.begin(), temp_result.end());
        }
        return ret;
    }

    vector<TreeNode*> combiner(const vector<TreeNode*>& left_nodes, const int parent_index, const vector<TreeNode*>& right_nodes) {
        vector<TreeNode*> ret;
        ret.reserve(left_nodes.size() * right_nodes.size());
        for (const auto& left_node: left_nodes) {
            for (const auto& right_node : right_nodes) {
                TreeNode* new_node = new TreeNode(parent_index);
                new_node->left = left_node;
                new_node->right = right_node;
                ret.push_back(new_node);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<TreeNode*> result = s.generateTrees(4);
    cout << result.size() << endl;
    return 0;
}
