#include <stack>
#include <queue>
#include <cassert>
#include <iostream>

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (_transformed) {
            step_forward(1);
            _transformed = false;
        }
        _queue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!_transformed) {
            step_forward(_queue.size() - 1);
        }
        _queue.pop();
        _transformed = false;
    }

    // Get the top element.
    int top() {
        if (!_transformed) {
            _transformed = step_forward(_queue.size() - 1);
        }
        return _queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return _queue.empty();
    }
private:
    std::queue<int> _queue;
    bool _transformed;
    bool step_forward(int steps) {
        if (steps > 0) {
            for (int i = 0; i < steps; ++i) {
                _queue.push(_queue.front());
                _queue.pop();
            }
            return true;
        }
        return false;
    }
};

int main() {
    Stack test_stack;
    std::stack<int> compare_stack;
    // basic check
    for (int i = 0; i < 100; ++i) {
        if (i %4 == 1) {
            test_stack.push(i);
            compare_stack.push(i);
        } else if (i % 4 == 2) {
            assert(test_stack.top() == compare_stack.top());
        } else if (i % 4 == 3) {
            test_stack.pop();
            compare_stack.pop();
        } else {
            assert(test_stack.empty() == compare_stack.empty());
        }
    }
    // 1, 2 check
    test_stack.push(0);
    test_stack.push(1);
    assert(test_stack.top() == 1);
    test_stack.pop();
    assert(test_stack.top() == 0);
    std::cout << "pass" << std::endl;
    return 0;
}
