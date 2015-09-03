#include <vector>
#include <iostream>

using namespace std;

// next time re-write
class Solution {
public:
    int numTrees(int n) {
        vector<int> cache;
        cache.reserve(n + 1);
        return numTrees_helper(n, cache);
    }

    int numTrees_helper(const int n, vector<int>& cache) {
        if (n == 0) {
            return 1;
        }
        // recursive call to calculate all previous nums
        cache.push_back(numTrees_helper(n - 1, cache));
        if (n == 1 || n == 2) {
            return n;
        }
        int ret = 0;
        if (n % 2 == 1) {
            ret += cache[n / 2] * cache[n / 2];
        }
        for (int i = 0; i < n/2; ++i) {
            ret += 2 * cache[n - i -1] * cache[i];
        }
        return ret;
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 10; ++i) {
        int num = s.numTrees(i);
        cout << i << ", num: " << num << endl;
    }
    return 0;
}
