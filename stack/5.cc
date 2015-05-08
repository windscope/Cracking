#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class MyQueue{
private:
    stack<int> insideStack[2];// stack 0 for pushing data, stack 1 for poping
public:
    bool empty(){
        return (insideStack[0].empty() && insideStack[1].empty());
    }
    
    void push(int value){
        insideStack[0].push(value);
    }
    
    int move(){
        if(empty()){
            cout<<"error: pop empty queue\n";
            return 0;// cannot move the stack
        }
        else if(insideStack[1].empty()){
            while(!insideStack[0].empty()){
                insideStack[1].push(insideStack[0].top());
                insideStack[0].pop();
            }
            return 1;// move the stack
        }
        else return 2;// don't have to move the stack
        
    }
    void pop(){
        if(!move()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        insideStack[1].pop();
    }
    int front(){
        if(!move()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return insideStack[1].top();
        
    }
};  

int main(){
    MyQueue que;
    que.push(1);
    que.push(2);
    que.push(3);
    assert(que.front()==1);
    que.push(4);
    que.pop();
    assert(que.front()==2);
    cout<<"You win!"<<endl;
}
