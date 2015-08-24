// Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_height = dfsHeight(left);
        int right_height = dfsHeight(right);
        if (left_height == -1 || right_height == -1) {
            return -1;
        }
        if (abs(left_height - right_height) > 1) {
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
};
