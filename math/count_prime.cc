#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(const int n) {
        int count = 0;
        if (n <= 1) {
            return 0;
        }
        for (int i = 2; i <= n; ++i) {
            if (composites.find(i) == composites.end()) {
                if (is_prime(i, n)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool is_prime(const int n, const int limit) {
        for (auto prime : primes) {
            if (n % prime == 0) {
                return false;
            }
        }
        primes.push_back(n);
        for (auto prime: primes) {
            int x = n;
            while(x * prime < limit) {
                x *= prime;
                composites.insert(x);
            }
        }
        return true;
    }

    int countPrimes2(const int n) {
        int count = 0;
        if (n <= 1) {
            return count;
        }
        bool* is_prime = new bool[n];
        memset(is_prime, true, n);
        for (int i = 2; i * i < n; ++i) {
            if (!is_prime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                count++;
            }
        }
        return count;
    }

private:
    vector<int> primes;
    unordered_set<int> composites;
};

int main() {

    Solution s;
    cout << s.countPrimes(100) << endl;
    cout << s.countPrimes2(100) << endl;
    return 0;
}
