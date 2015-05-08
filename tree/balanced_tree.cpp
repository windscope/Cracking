// Implement a function to check if a tree is balanced.
// For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf
// nodes differ in distance from the root by more than one.

#include <cassert>
#include <iostream>
#include <set>

#include "tree.h"

using namespace crack;

class Solution {
public:
    Solution() : _gap(2) {}
    explicit Solution(int gap) : _gap(gap) {}
public:
    bool is_balanced(const Tree& tree) {
        std::set<int> distance_set;
        int count = 0;
        pre_order_traversal(tree.root(), &distance_set, count);
        if (distance_set.empty()) {
            return true;
        }
        int smallest_distance = *distance_set.begin();
        int largest_distance = *distance_set.rbegin();
        if (!(tree.root()->has_left() && tree.root()->has_right())) {
            smallest_distance = 1;
        }
        // For debugging
        // std::cout << "Largest is " << largest_distance << std::endl;
        // std::cout << "Smallest is " << smallest_distance << std::endl;
        return (largest_distance - smallest_distance) <= _gap;
    }
    void pre_order_traversal(const Tree::Node* node, std::set<int>* distances, const int& count) {
        if (nullptr != node) {
            int distance = count + 1;
            if ((!node->has_left()) && (!node->has_right())) {
                    distances->insert(distance);
            }
            pre_order_traversal(node->left(), distances, distance);
            pre_order_traversal(node->right(), distances, distance);
        }
    }
private:
    int _gap;
};

int main(void) {
    Tree tree;
    Solution solution;
    assert(solution.is_balanced(tree));
    std::vector<int> data = {5,4,3,2,1};
    tree.insert(data);
    assert(!solution.is_balanced(tree));
    tree.add_node(8);
    assert(!solution.is_balanced(tree));
    tree.add_node(6);
    assert(solution.is_balanced(tree));
    std::cout << "You passed!"<<std::endl;
}
