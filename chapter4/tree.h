#ifndef _TREE_H_
#define _TREE_H_
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Node{
    public:
        Node();
        Node(int key);
        void setKey(int key);
        Node *left();
        Node *right();
        int key();
        void setLeft(Node *left);
        void setRight(Node *right);
    private:
        int _key;
        Node *_left;
        Node *_right;
};


class Tree{
    private:
        Node *_root;
        void addNode(int key, Node *leaf);
        void freeNode(Node *leaf);
    public:
        Tree();
        ~Tree();
        Node *root(){return _root;}
        void addNode(int key);
        void preOrder(Node* leaf);
        void inOrder(Node *leaf);
        void postOrder(Node *leaf);
        void iterPreOrder(Node *leaf);
        void iterInOrder(Node *leaf);
        void iterPostOrder(Node *leaf);

};
#endif
