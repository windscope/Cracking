#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Stack{
private:
    int *buf, cur, capacity;
public:
    Stack(){
        capacity = 2;
        cur = -1;
        buf = new int[capacity];
    }

    Stack(int initSize){
        capacity = initSize;
        cur = -1;
        buf = new int[capacity];
    }
    ~Stack(){
        delete[] buf;
    }
    bool full(){
        return (cur+1 == capacity);
    }
    bool empty(){
        return (cur == -1);
    }
    int top(){
        if(!empty())
            return buf[cur];
        else return -1;
    }
    void push(int data){
        buf[++cur] = data;
    }
    void pop(){
        cur--;
    }
};

class multiStack{
private:
    Stack *buf;
    int cur,capacity;
public:
    multiStack(int size){
        cur = -1;
        capacity = size;
        buf = new Stack[size];
    }
    ~multiStack(){
        delete[] buf;
    }
    void push(int value){
        if(cur == -1)
            buf[++cur].push(value);
        else if(buf[cur].full())
            buf[++cur].push(value);
        else
            buf[cur].push(value);
    }
    void pop(){
        while(buf[cur].empty())
            --cur;
        buf[cur].pop();
        while(buf[cur].empty()&&cur!=-1)
            --cur;
    }
    void popAt(int stackNum){
        while(buf[stackNum].empty())
            stackNum -= 1;
        buf[stackNum].pop();
    }
    int top(){
        int tempCur = cur;
        while(buf[tempCur].empty())
            --tempCur;
        return buf[tempCur].top();
    }
    bool full(){
        if(cur+1 == capacity) return buf[cur].full();
        else return false;
    }
    bool empty(){
        return cur==-1;
    }
};


int main(){
    multiStack a(5);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.popAt(1);
    a.popAt(1);
    a.popAt(2);
    a.popAt(2);
    a.pop();
    assert(a.empty());
    cout<<"You win!"<<endl;
    return 0;

}
