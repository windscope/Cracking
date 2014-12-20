Tree::Tree(){
    _root = new Node;
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

void addNode(int key){
    if(key != root->key){
    if(key<root->key)    
    }
}
