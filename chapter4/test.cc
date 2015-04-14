#include "tree.h"

int main(){
    Tree test;
    test.addNode(9);
    test.addNode(5);
    test.addNode(3);
    test.addNode(2);
    test.addNode(4);
    test.addNode(1);
    test.addNode(6);
    test.addNode(8);
    test.addNode(7);
    test.preOrder(test.root());
    test.inOrder(test.root());
    test.postOrder(test.root());
    test.iterPreOrder(test.root());
    //test.iterPostOrder(test.root());
    test.iterInOrder(test.root());
    cout<<"hello"<<endl;
    return 0;
}
