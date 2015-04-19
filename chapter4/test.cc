#include "tree.h"

#include <iostream>


int main(){
    crack::Tree test;
    test.add_node(9);
    test.add_node(5);
    test.add_node(3);
    test.add_node(2);
    test.add_node(4);
    test.add_node(1);
    test.add_node(6);
    test.add_node(8);
    test.add_node(7);
    test.pre_order(test.root());
    std::cout << "after preorder" << std::endl;
    test.in_order(test.root());
    std::cout << "after in order" << std::endl;
    test.post_order(test.root());
    std::cout << "after post order" << std::endl;
    return 0;
}

