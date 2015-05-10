#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    // Basic idea: a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b)), not my code
//    int divide(int dividend, int divisor) {
//        if (dividend==0) return 0;
//        if (divisor==0) return INT_MAX;
//        long long res=double(exp(log(fabs(dividend))-log(fabs(divisor))));
//        if ((dividend<0)^(divisor<0)) res=-res;
//        if (res>INT_MAX) res=INT_MAX;
//        return res;
//    }
    
    
    // binary search, not my code
    int divide(int dividend, int divisor) {
        // for cases where dividend or divisor is INT_MIN,
        // by using a higher type, we take the whole number
        // else abs cannot work since its based on 2's complement
        // and 2's complement of n bit number is undefined if its
        // the min number. try taking out the 2's complement of
        // -8 for a 4 bit number, behaviour is undefined
        long a = labs(dividend);
        long b = labs(divisor);
        long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        // overflow cases : denominator == 0 or dividing by a number makes the number
        // greater than INT_MAX
        if (b == 0 || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        } else if (b == 1) {
            return sign * a;
        }
        
        
        long result = 0;
        int i = 0;
        while(a >= b) {
            i = 0;
            while(a >= b<<i) {
                a -= b<<i;
                result += 1<<i;
                i++;
            }
        }
        return (sign * result);
    }
    
};

int main() {
    Solution s;
    cout << s.divide(8, 2) << endl;
    return 0;
}
