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

    vector<TreeNode*> divider(const int i, const int j) {
        if (i > j) {
            return {nullptr};
        }
        if (i == j) {
            return {node_creater(i, j)};
        } else if (i + 1 == j) {
            return {node_creater(i, j), node_creater(j, i)};
        } else {
            vector<TreeNode*> ret_nodes;
            for (int x = i - 1 ; x + 1 <= j; ++x) {
                vector<TreeNode*> left_nodes = divider(i, x);
                vector<TreeNode*> right_nodes = divider(x + 2, j);
                vector <TreeNode*> level_nodes = combiner(left_nodes, x + 1, right_nodes);
                ret_nodes.reserve(ret_nodes.size() + level_nodes.size());
                ret_nodes.insert(ret_nodes.end(), level_nodes.begin(), level_nodes.end());
            }
            return ret_nodes;
        }
    }

    TreeNode* node_creater(const int parent_index, const int child_index) {
        if (parent_index == child_index) {
            return new TreeNode(parent_index);
        }
        TreeNode* parent_node = new TreeNode(parent_index);
        TreeNode* child_node = new TreeNode(child_index);
        if (parent_index > child_index) {
            parent_node->left = child_node;
        } else {
            parent_node->right = child_node;
        }
        return parent_node;
    }

    vector<TreeNode*> combiner(vector<TreeNode*>& left_nodes, const int i, vector<TreeNode*>& right_nodes) {
        vector<TreeNode*> ret;
        ret.reserve(right_nodes.size() * left_nodes.size());
        for (auto left_node : left_nodes) {
            for (auto right_node : right_nodes) {
                TreeNode* this_node = new TreeNode(i);
                this_node->left = left_node;
                this_node->right = right_node;
                ret.push_back(this_node);
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
