// Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Algortithm: 1. In order traversal and remember the count of the binary tree
//             2. If the tree has a lot of operation, we need to make the tree a self-balanced
//                binary tree, and record the length, in which case we can then use binary search
//                help us finish the task

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = nullptr;
        int count = 0;
        in_order_traversal(root, k, &count, &result);
        return result->val;
    }
    void in_order_traversal(TreeNode* node, const int k, int* count, TreeNode** result) {
        if (node != nullptr) {
            in_order_traversal(node->left, k, count, result);
            (*count)++;
            if (*count == k) {
                *result = node;
            }
            in_order_traversal(node->right, k, count, result);
        }
    }
};

int main() {
    // construct the test tree
    TreeNode* test_root = new TreeNode(4);
    test_root->left = new TreeNode(2);
    test_root->right = new TreeNode(5);
    test_root->left->left = new TreeNode(1);
    test_root->left->right = new TreeNode(3);

    Solution s;
    for (int i = 1; i < 6; ++i) {
        assert(s.kthSmallest(test_root, i) == i);
    }
    cout << "You passed" << endl;
    return 0;
}
