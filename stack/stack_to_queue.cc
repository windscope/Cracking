#include <stack>
#include <queue>
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        _in_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        move_data();
        _out_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        move_data();
        return _out_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return _in_stack.empty() && _out_stack.empty();
    }
private:
    std::stack<int> _in_stack;
    std::stack<int> _out_stack;
    bool move_data() {
        if (!_out_stack.empty()) {
            return false;
        }
        while (!_in_stack.empty()) {
            _out_stack.push(_in_stack.top());
            _in_stack.pop();
        }
        return true;
    }
};

int main() {
    Queue test_q;
    std::queue<int> compare_q;
    for (int i = 1; i <= 100; ++ i) {
        if (i % 5 == 1 || i % 5 == 2) {
            test_q.push(i);
            compare_q.push(i);
        } else if (i % 5 == 3) {
            assert(compare_q.front() == test_q.peek());
        } else if (i % 5 == 4) {
            test_q.pop();
            compare_q.pop();
        } else {
            assert(test_q.empty() == compare_q.empty());
        }
    }
    cout << "passed" << endl;
    return 0;
}
