// Author windscope <windcope@gmail.com>

#include "tree.h"

#include <iostream>

namespace crack {

void Tree::free_node(Node *leaf) {
    if (leaf->has_left()) {
        free_node(leaf->mutable_left());
    }
    if (leaf->has_right()) {
        free_node(leaf->mutable_right());
    }
    delete leaf;
}

Tree::~Tree() {
    free_node(_root);
}

void Tree::add_node(int value) {
    // if root
    if (nullptr == _root ) {
        _root = new Node(value);
    } else {
        add_node(value, _root);
    }
}

void Tree::add_node(int value, Node* leaf) {
    if (value < leaf->value()) {
        if (leaf->has_left()) {
            add_node(value, leaf->mutable_left());
        } else {
            Node* left = new Node(value);
            leaf->set_left(left);
        }
    } else {
        if (leaf->has_right()) {
            add_node(value, leaf->mutable_right());
        } else {
            Node* right  = new Node(value);
            leaf->set_right(right);
        }
    }
}

void Tree::insert(std::vector<int> data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        add_node(*it);
    }
}

void Tree::post_order(const Node* leaf) const {
    if (nullptr != leaf) {
        post_order(leaf->left());
        post_order(leaf->right());
        std::cout << leaf->value() << std::endl;
    }
}

void Tree::in_order(const Node* leaf) const {
    if (nullptr != leaf) {
        in_order(leaf->left());
        std::cout << leaf->value() << std::endl;
        in_order(leaf->right());
    }
}

void Tree::pre_order(const Node* leaf) const {
    if (nullptr != leaf) {
        std::cout << leaf->value() << std::endl;
        pre_order(leaf->left());
        pre_order(leaf->right());
    }
}

} // namespace crack
