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
    // not my code
    /*
        Newton's Iterative Method:
     
         x(n+1) = xn - f(xn) / f'(xn)
         
         x = sqrt(S) where S is the parameter x x^2 = S
         
         f(xn) = xn^2 - S = 0 f'(xn) = 2 * xn
         
         From the first sentence, x(n+1) = xn - (xn^2 - S) / 2 * xn x(n+1) = (xn + S / x_n) / 2
         
         From the code, ans = (ans + x / ans) / 2;
         
         I.E. get x where f(x) = x^7 + x^4 + x^2 + 1 = 0
         
         f(x) = x^7 + x^4 + x^2 + 1 f'(x) = 7x^6 + 4x^3 + 2*x
         
         while( > delta) { x(n+1) = xn - (xn^7 + xn^4 + xn^2 + 1) / (7*xn^6 + 4x_n^3 + 2x_n) }
         
         return x(n_1) // depending initial value and the status of the graph, the result may vary.
     */
    int mySqrt(int x) {
        double ans    = x;
        double delta  = 0.0001;
        while (fabs(pow(ans, 2) - x) > delta) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};

int main() {
    int i = 10;
    
    Solution s;
    cout << s.mySqrt(i) << endl;
}