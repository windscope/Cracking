// Given a binary search tree, design an algorithm which creates a linked list of all the nodes
// at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).

#include <iostream>
#include <list>
#include <map>

#include "tree.h"
namespace {
void travers_tree(std::map<int, std::list<int>>* level_dict,
        const crack::Tree::Node* node, const int count) {
    if (node != nullptr) {
        int depth = count + 1;
        if (level_dict->find(depth) == level_dict->end()) {
            std::list<int> level_list;
            (*level_dict)[depth] = level_list;
        }
        (*level_dict)[depth].push_back(node->value());
        travers_tree(level_dict, node->left(), depth);
        travers_tree(level_dict, node->right(), depth);
    }
}

void print_map(const std::map<int, std::list<int>>& level_dict) {
    for (auto mit = level_dict.begin(); mit != level_dict.end(); ++mit) {
        std::cout << "Level " << mit->first << ": ";
        for(auto lit = mit->second.begin(); lit != mit->second.end(); ++lit) {
            std::cout << *lit <<" ";
        }
        std::cout << std::endl;
    }
}

void sorted_array_to_btree(crack::Tree* tree, int* sorted_array, int size) {
    if (size == 0) {
        return;
    } else if (size == 1) {
        tree->add_node(sorted_array[0]);
        return;
    }
    int mid_index = size/2-1+size%2; // get the middle index
    tree->add_node(sorted_array[mid_index]);
    sorted_array_to_btree(tree, sorted_array, (size-1)/2);
    sorted_array_to_btree(tree, sorted_array + size/2 + size %2, (size-1)/2 + 1- size%2);
}

void to_linked_list(const crack::Tree& tree, std::map<int, std::list<int>>* level_dict) {
    travers_tree(level_dict, tree.root(), 0);
}

} // anonymous namespace


int main() {
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    crack::Tree tree;
    sorted_array_to_btree(&tree, a, 20);
    std::map<int, std::list<int>> level_map;
    to_linked_list(tree, &level_map);
    print_map(level_map);
    return 0;
}
