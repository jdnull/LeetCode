#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
// This method costs too much time
//    int climbStairs(int n) {
//        if (n < 0) {
//            return 0;
//        }
//        if (n <= 1) {
//            return 1;
//        }
//        return climbStairs(n-1)+climbStairs(n-2);
//    }
    int climbStairs(int n) {
        if (n < 0) {
            return 0;
        }
        if (n <= 1) {
            return 1;
        }
        int pre = 1, current = 2, i = 3;
        while (i <= n) {
            int t = current;
            current += pre;
            pre = t;
            i++;
        }
        return current;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}
