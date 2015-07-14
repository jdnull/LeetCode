#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // time limit exceed
//    int countPrimes(int n) {
//        int count = 0;
//        for (int i = 1; i < n; i++) {
//            if (isPrime(i)) count++;
//        }
//        return count;
//    }
//    
//    bool isPrime(int num) {
//        if (num <= 1) return false;
//        // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
//        // to avoid repeatedly calling an expensive function sqrt().
//        for (int i = 2; i * i <= num; i++) {
//            if (num % i == 0) return false;
//        }
//        return true;
//    }
    
    int countPrimes(int n) {
        vector<int> isPrime(n, false);
        for (int i = 2; i < n; i++) {
            isPrime[i] = true;
        }
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(20) << endl;
}