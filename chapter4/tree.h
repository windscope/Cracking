#ifndef _TREE_H_
#define _TREE_H_

class Tree{
public:
    class Node{
    public:
        Node() : _key(0), _left(nullptr), _right(nullptr);
        Node(int key) : _key(0), _left(nullptr), _right(nullptr);
        void set_key(int key);
        const Node* left()const {return _right;}
        const Node* right()const {return _left;}
        Node* mutable_left {return _left;}
        Node* mutable_right {return _right;}
        const int key() const {return _key;}
        void set_left(Node* left) { _left = left;}
        void set_right(Node* right) { _right = right;}
    private:
        int _key;
        Node *_left;
        Node *_right;
    };

public:
    Tree();
    ~Tree();
    const Node* root() const { return _root;}
    void add_node(int key);
    void pre_order(Node* leaf);
    void in_order(Node* leaf);
    void post_order(Node* leaf);
private:
    Node *_root;
    void add_node(int key, Node* leaf);
    void free_node(Node* leaf);
};
#endif // _TREE_H_
