// Author: Windscope <windscope@gmail.com>
// Question: Write a function to check whether a given tree is a binary search tree(bst)

#include <cassert>
#include <iostream>
#include <vector>

#include "tree.h"

namespace crack {
bool is_binary_tree (const Tree::Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->has_left()) {
        if (node->left()->value() > node->value()) {
            return false;
        }
    }
    if (node->has_right()) {
        if (node->right()->value() < node->value()) { 
            return false;
        }
    }
    return is_binary_tree(node->left()) && is_binary_tree(node->right());
}

} // namespace crack

int main() {
    crack::Tree tree;
    std::vector<int> data = {2,1,3};
    tree.insert(data);
    assert(crack::is_binary_tree(tree.root()));
    tree.mutable_root()->set_value(5);
    assert(!crack::is_binary_tree(tree.root()));
    std::cout << "Passed" << std::endl;
    return 0;
}
