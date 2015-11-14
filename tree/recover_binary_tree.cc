// Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/
// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        TreeNode* temp = nullptr;
        vector<TreeNode*> nodes(2, nullptr);
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                if (temp != nullptr && temp->val > cur->val) {
                    if (nodes[0] == nullptr) {
                        nodes[0] = temp;
                        nodes[1] = cur;
                    } else {
                        nodes[1] = cur;
                    }
                }
                temp = cur;
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    if (temp != nullptr && temp->val > cur->val) {
                        if (nodes[0] == nullptr) {
                            nodes[0] = temp;
                            nodes[1] = cur;
                        } else {
                            nodes[1] = cur;
                        }
                    }
                    temp = cur;
                    cur = cur->right;
                }
            }
        }
        swap(nodes[1]->val, nodes[0]->val);
    }

    void swap(int& left, int& right) {
        int temp = left;
        left = right;
        right = temp;
    }
};

int main() {
    return 0;
}
