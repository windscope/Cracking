// Source : https://leetcode.com/problems/rectangle-area/

/********************************************************************************** 
 * 
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * 
 *                      Y                                        
 *                      ^                                        
 *                      |                                        
 *                      |                                        
 *                      |                                        
 *                      |                                        
 *                      |     (C,D):(3,4)                        
 *            +------------------+                               
 *            |         |        |                               
 *            |         |        |                               
 *            |         |        |               (G,H):(9,2)     
 *            |         +----------------------------+           
 *            |         |        |                   |           
 *            |         |        |                   |           
 *            |         |        |                   |           
 *            +---------|--------+-------------------|---------> X
 *      (A,B):(-3,0)    |                            |           
 *                      +----------------------------+           
 *                  (E,F):(0,-1)                                 
 *      
 *      
 *      
 * Assume that the total area is never beyond the maximum possible value of int.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <cassert>
using namespace std;

class Solution{
public:
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int base = sum_rect(A, B, C, D) + sum_rect(E, F, G, H);
    int L, N, R, U;
    if (A >= G || C <= E || B >= H || D <= F) {
        return base;
    }
    L = A > E ? A : E;
    R = C > G ? G : C;
    N = B > F ? B : F;
    U = D > H ? H : D;
    return base - sum_rect(L, N, R, U);
}

int sum_rect(int L, int N, int R, int U) {
    return (U - N) * (R - L);
}


};

int main() {
    Solution s;
    // point
    assert(s.computeArea(1, 1, 1, 1, 1, 1, 1, 1) == 0);
    // no overlap
    assert(s.computeArea(-2, 0, 0, 2, 0, 0, 2, 2) == 8);
    // overlap
    assert(s.computeArea(-2, -2, 2, 2, 0, 0, 4, 4) == 28);
    cout << "Passed" << endl;
}
