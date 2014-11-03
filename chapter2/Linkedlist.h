#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct Node
{
    int data;
    Node *next;
};

class Linkedlist
{
    public:
        Node *head;
        Linkedlist();
        ~Linkedlist();
        void insert(int data);
        void createCycle();
    private:
        Node *tail; // Add for O(1) insertion
}
#endif
