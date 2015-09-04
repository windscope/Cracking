// https://leetcode.com/problems/binary-tree-paths/
// Binary Tree Paths
// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]

// Definition for a binary tree node.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) {
            return {};
        }
        string this_path = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return {this_path};
        }
        path(root->left, this_path, ret);
        path(root->right, this_path, ret);
        return ret;
    }
    void path(TreeNode* node, const string& prev_path, vector<string>& result) {
        if (node) {
            string this_path = prev_path + "->" + to_string(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(this_path);
                return;
            }
            path(node->left, this_path, result);
            path(node->right, this_path, result);
        }
    }

};


int main() {
    unique_ptr<TreeNode> root(new TreeNode(5));
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->right = new TreeNode(10);
    // the result should be in the following order:
    Solution s;
    vector<string> result;
    result = s.binaryTreePaths(root.get());
    for (const auto& s : result) {
        cout << s << endl;
    }
    return 0;
}
