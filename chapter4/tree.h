// Author windscope <windcope@gmail.com>

#ifndef _TREE_H_
#define _TREE_H_

#include <vector>
namespace crack {

class Tree{
public:
    class Node{
    public:
        Node() : _value(0), _left(nullptr), _right(nullptr) {}
        explicit Node(int value) : _value(value), _left(nullptr), _right(nullptr) {}
        const Node* left() const { return _right; }
        const Node* right() const { return _left; }
        Node* mutable_left() { return _left; }
        Node* mutable_right() { return _right; }
        const int value() const { return _value; }
        void set_left(Node* left) { _left = left; }
        void set_right(Node* right) { _right = right; }
        void set_value(int value) { _value = value; }
        bool has_left() const { return (nullptr != _left); }
        bool has_right() const { return (nullptr != _right); }
    private:
        int _value;
        Node *_left;
        Node *_right;
    };

public:
    Tree() : _root(nullptr) {}
    ~Tree();
    const Node* root() const { return _root;}
    void add_node(int value);
    void pre_order(const Node* leaf) const;
    void in_order(const Node* leaf) const;
    void post_order(const Node* leaf) const;
    void insert(std::vector<int> data);
private:
    Node *_root;
    void add_node(int value, Node* leaf);
    void free_node(Node* leaf);
};

} // namespace crack

#endif // _TREE_H_
