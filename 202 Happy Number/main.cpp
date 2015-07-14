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
    // not my code, O(1) space complexity
    // int digitSquareSum(int n) {
    //     int sum = 0, tmp;
    //     while (n) {
    //         tmp = n % 10;
    //         sum += tmp * tmp;
    //         n /= 10;
    //     }
    //     return sum;
    // }
    
    // bool isHappy(int n) {
    //     int slow, fast;
    //     slow = fast = n;
    //     do {
    //         slow = digitSquareSum(slow);
    //         fast = digitSquareSum(fast);
    //         fast = digitSquareSum(fast);
    //     } while(slow != fast);
    //     if (slow == 1) return 1;
    //     else return 0;
    // }

    bool isHappy(int n) {
        map<int, int> m;
        int sum = n;
        while (sum != 1) {
            m[sum] = 1;
            int t = sum;
            sum = 0;
            while (t != 0) {
                int digit = t % 10;
                sum += digit*digit;
                t /= 10;
            }
            if (m.find(sum) != m.end()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
}