#include "tree.h"

using namespace std;

Node::Node(){
    _left = nullptr;
    _right  = nullptr;
    _key = -1;
}

Node::Node(int key){
    _left = nullptr;
    _right = nullptr;
    _key = key;
}

void Node::setKey(int key){
    _key = key;
}

Node *Node::left(){
    return _left;
}

Node *Node::right(){
    return _right;
}

int Node::key(){
    return _key;
}

void Node::setLeft(Node *left){
        _left = left;
}

void Node::setRight(Node *right){
    _right = right;
}


Tree::Tree(){
    _root = nullptr;
}

Tree:: ~Tree(){
    freeNode(_root);
}

void Tree::freeNode(Node *leaf){
    if(leaf!=nullptr){
        freeNode(leaf->left());
        freeNode(leaf->right());
        delete leaf;
    }
}

void Tree::addNode(int key){
    if(_root == NULL){
        cout<<"Adding root node with key: "<<key<<endl;
        Node *root  = new Node(key);
        _root = root;
    }
    else{
        cout<<"Adding the leaf node with key: "<<key<<endl;
        addNode(key, _root);
    }
}

void Tree::addNode(int key, Node *leaf){
    if(key <= leaf->key()){
        if(leaf->left() != nullptr){
            addNode(key, leaf->left());
        }
        else{
            Node *left = new Node(key);
            leaf->setLeft(left);
        }
    }
    else{
        if(leaf->right() != nullptr){
            addNode(key, leaf->right());
        }
        else{
            Node *right = new Node(key);
            leaf->setRight(right);
        }
    }
}


void Tree::preOrder(Node *leaf){
    if(leaf != nullptr){
        cout<<leaf->key()<<" ";
        preOrder(leaf->left());
        preOrder(leaf->right());
    }
}

void Tree::postOrder(Node *leaf){
    if(leaf != nullptr){
        postOrder(leaf->left());
        postOrder(leaf->right());
        cout<<leaf->key()<<" ";
    }
}

void Tree::inOrder(Node *leaf){
    if(leaf != nullptr){
        inOrder(leaf->left());
        cout<<leaf->key()<<" ";
        inOrder(leaf->right());
    }
}

void Tree::iterPreOrder(Node *leaf){
    stack<Node *> parent;// parent stack that hold the parent node for future reference
   while(!parent.empty() || leaf != nullptr){
        if(leaf != nullptr){
            cout<<leaf->key()<<" "; 
            if(leaf->right() != nullptr)
                parent.push(leaf->right());
            leaf = leaf->left();
        }
        else{
            leaf = parent.top();
            parent.pop();
        }
    }
}

void Tree::iterInOrder(Node *leaf){
    stack<Node *>parent;
    while(!parent.empty() || leaf != nullptr){
        if(leaf != nullptr){
            parent.push(leaf);
            leaf = leaf->left();

        }
        else{
            leaf = parent.top();
            parent.pop();
            cout<<leaf->key()<<" ";
            leaf = leaf->right();
        }
    }
}
/*
void Tree::iterPostOrder(Node *leaf){
    stack<Node *>parent;
    Node *nodeVisited;
    while(!parent.empty() || leaf != nullptr){
        if(leaf != nullptr){
            
        }
    }
}
*/

