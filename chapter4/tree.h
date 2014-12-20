Class Node{
    public:
        Node(){
            _left = nullptr;
            _right  = nullptr;
            _key = -1;
        }
        void setKey(int value){ _key = value; }
        Node *left() {return _left;}
        Node *right() {return _right;}
        int key(){return _key;}
        void setLeft(Node *left){
            _left = left;
        } 
        void setRight(Node *right){
            _right = right;
        }

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
        Node *root{return _root;}
        void addNode(int key);
        void preOder(Node* leaf);
        void inOrder(Node *leaf);
        void postOrder(Node *leaf);
        void iterPreOrder(Node *leaf);
        void iterInOrder(Node *leaf);
        void iterPostOder(Node *leaf);

}
