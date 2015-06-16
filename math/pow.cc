// Implement pow(x, n).
// author windscope<windscope@gmail.com>
//
#include <cassert>
#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0){
            return 1;
        } else if(n < 0) {
            x = 1/x;
            n = -n;
        }
        if (n == 1) {
            return x;
        } else if (n == 2) {
            return x*x;
        }
        double result = myPow(x, n/2);
        if (n%2 == 0)
            return result * result;
        else
            return x*result*result;
    }
};

int main(void) {
    using std::cout;
    using std::endl;
    Solution s;
    assert(s.myPow(4, 5) == 1024);
    assert(s.myPow(4, -5) == 1.0/1024.0);
}
