#include "tree.h"

using namespace std;

Node::Node(){}

Node::Node(int key){}

Node::setKey(int key){}

Node *Node::left(){}

Node *Node::right(){}

void *Node::setLeft(){}

void *Node::setRight(){}

Tree::Tree(){}

void Tree::freeNode(Node *leaf){}

Tree::~Tree(){}

void Tree::addNode(int key){}

Node *Tree::insert(int key, Node *leaf){}

void Tree::preOrder(Node *leaf){}

void Tree::postOrder(Node *leaf){}

void Tree::inOrder(Node *leaf){}
