// Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Given a binary tree
//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// For example,
// Given the following perfect binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

// Follow up for problem "Populating Next Right Pointers in Each Node".
// What if the given tree could be any binary tree? Would your previous solution still work?

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        root->next = nullptr;
        // for first problem, dfs_traverse is ok
        // post_order_traverse(root);
        // for follow up
        iterative_algorithm(root);
    }

    void post_order_traverse(TreeLinkNode* node) {
        if (node->left != nullptr && node->right != nullptr) {
            node->left->next = node->right;
            if (node->next != nullptr) {
                node->right->next = node->next->left;
            } else {
                node->right->next = nullptr;
            }
            post_order_traverse(node->left);
            post_order_traverse(node->right);
        }
    }
    void self_connector(TreeLinkNode* node) {
        if (node != nullptr) {
            if (node->left != nullptr && node->right != nullptr) {
                node->left->next = node->right;
            }
            self_connector(node->left);
            self_connector(node->right);
        }
    }

    void iterative_algorithm(TreeLinkNode* node) {
        TreeLinkNode* head = nullptr;
        TreeLinkNode* next_from = nullptr;
        TreeLinkNode* current = node;
        while (current != nullptr) {
            // inner loop iterate through the same level
            while (current != nullptr) {
                if (current->left != nullptr) {
                    if (next_from != nullptr) {
                        next_from->next = current->left;
                    }
                    next_from = current->left;
                    if (head == nullptr) {
                        head = current->left;
                    }
                }
                if (current->right != nullptr) {
                    if (next_from != nullptr) {
                        next_from->next = current->right;
                    }
                    next_from = current->right;
                    if (head == nullptr) {
                        head = current->right;
                    }
                }
                current = current->next;
            }
            current = head;
            next_from = nullptr;
            next_to = nullptr;
            head = nullptr;
        }
    }
};

int main() {
    return 0;
}
