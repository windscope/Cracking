#include <iostream>
#include <assert.h>

using namespace std;

struct Node
{
    int data;
    int prevIdx;
};

class Stack3
{
    private:
    int size;
    int curPtr[3];// current index "pointer" point to the most recent accessed index of each stack. 
    int curIdx; // current index for next data to insert; 
    Node *buf;
    public: 
        Stack3(int size = 300);
        ~Stack3();
        int top(int stackIdx);
        int push(int value, int stackIdx);
        int pop(int stackIdx);
        int check(){ return curIdx;}
};

Stack3:: Stack3(int size)
{
    this->size = size;
    buf = new Node[size];
    curIdx = curPtr[0] = curPtr[1] = curPtr[2] = -1;
    for(int i = 0;i<size; ++i)// initialize the buffer for storage. 
    {
        buf[i].data = 0;
        buf[i].prevIdx = -2;
    }
};

Stack3::~Stack3()
{
    delete[] buf;
}

int Stack3:: top(int stackIdx)
{
    if(curPtr[stackIdx] == -1) 
    {
        cout<<"Not thing to peak\n";
        return -1;
    }
    int topIdx = curPtr[stackIdx];
    return buf[topIdx].data;
}

int Stack3::push(int value, int stackIdx)
{
    while(buf[curIdx].prevIdx != -2 && curIdx < size)// current node of buffer has already been used
        curIdx ++;
    if(curIdx+1 == size)// error handling
    {
        cout<<"Cannot grow, already reach the boundary of memory address"<<endl;
        return -1;
    }
    buf[curIdx].prevIdx = curPtr[stackIdx];
    buf[curIdx].data = value;
    curPtr[stackIdx] = curIdx;
    return 1;
}

int Stack3::pop(int stackIdx)
{
    int bufIdx = curPtr[stackIdx];
    if(bufIdx == -1){
        cout<<"Nothing to pop\n";
        return -1;
    }
    curPtr[stackIdx] = buf[bufIdx].prevIdx;
    buf[bufIdx].prevIdx = -2;
    if(bufIdx < curIdx) curIdx = bufIdx; 
    return 0;
}

int main(){
    Stack3 testStack(9);
    testStack.push(3,2);
    testStack.push(1,0);
    testStack.push(2,1);
    testStack.push(2,1);
    testStack.pop(0);
    assert(testStack.check() == 1);
    testStack.push(2,1);
    testStack.pop(1);
    testStack.pop(1);
    assert(testStack.check() == 1);
    testStack.pop(2);
    assert(testStack.pop(2) == -1);
    cout<<"Pass"<<endl;
    return 0;    
}
