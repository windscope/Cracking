// Author: windscope <windscope@gmail.com>

// Question:
// Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
// Thoughts
// Given a sorted array, the best way to create a balanced binary tree is to insert the middle value of each sub-array.

#include <iostream>
#include <set>
#include <cassert>

#include "tree.h"

namespace crack {
class Solution2 {
public:
    explicit Solution2() : _tree() {}
    virtual ~Solution2() {}
    void reset() {
        Tree _tree();
     }
    void create_balanced_tree(int* sorted_array, int size) {
        if (size == 0) {
            return;
        } else if (size == 1) {
            _tree.add_node(sorted_array[0]);
            return;
        }

        int mid_index = size/2-1+size%2; // get the middle index
        _tree.add_node(sorted_array[mid_index]);
        create_balanced_tree(sorted_array, (size-1)/2);
        create_balanced_tree(sorted_array + size/2 + size %2, (size-1)/2 + 1- size%2);
    }

    // for test
    bool is_balanced() {
        std::set<int> step_set;
        pre_order_traversed(&step_set, 0, _tree.root());
        if (step_set.empty())
            return true;
        int largest = *step_set.rbegin();
        int smallest = *step_set.begin();
        if (!(_tree.root()->has_left() && _tree.root()->has_right())) {
            smallest = 1;
        }
        std::cout << "Largest is " << largest << std::endl;
        std::cout << "Smallest is " << smallest << std::endl;
        return (largest - smallest) < 3;
    }

    void pre_order_traversed(std::set<int>* step_set, const int count, const Tree::Node* node) {
        if (node != nullptr) {
            int depth = count + 1;
            if (!node->has_left() && !node->has_right()) {
                step_set->insert(depth);
            }
            pre_order_traversed(step_set, depth, node->left());
            pre_order_traversed(step_set, depth, node->right());
        }
    }

    // for debug
    void get_tree_size(int* count, const Tree::Node* node) {
        if (node != nullptr) {
            ++(*count);
            get_tree_size(count, node->left());
            get_tree_size(count, node->right());
        }
    }

    void print_tree_size() {
        int count = 0;
        get_tree_size(&count, _tree.root());
        std::cout << "size is " << count << std::endl;
    }

    void in_order_print(const Tree::Node* node) {
        if (node != nullptr) {
            in_order_print(node->left());
            std::cout << node->value() << " ";
            in_order_print(node->right());
        }
    }

    void print_tree() {
        in_order_print(_tree.root());
    }
private:
    Tree _tree;
};
}  // crack



int main(void) {
    int data[9] = {1,2,3,4,5,6,7,8,9};
    crack::Solution2 s;
    s.create_balanced_tree(data, 9);
    assert(s.is_balanced());
    crack::Solution2 s2;
    int data2[8] = {2, 4, 6, 8, 10, 12, 13, 15};
    s2.create_balanced_tree(data2, 8);
    assert(s2.is_balanced());
    int data3[1] = {5};
    crack::Solution2 s3;
    s3.create_balanced_tree(data3, 1);
    assert(s3.is_balanced());
    int data4[2] = {0,5};
    crack::Solution2 s4;
    s3.create_balanced_tree(data4, 2);
    assert(s4.is_balanced());
    std::cout << "passed" <<std::endl;
    return 0;
}
