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
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        // zero numerator
        if (numerator == 0) return "0";
        
        string res;
        // determine the sign
        if (numerator < 0 ^ denominator < 0) res += '-';
        
        // remove sign of operands
        numerator = abs(numerator), denominator = abs(denominator);
        
        // append integral part
        res += to_string(numerator / denominator);
        
        // in case no fractional part
        if (numerator % denominator == 0) return res;
        
        res += '.';
        
        unordered_map<int, int> map;
        
        // simulate the division process
        for (int64_t r = numerator % denominator; r; r %= denominator) {
            
            // meet a known remainder
            // so we reach the end of the repeating part
            if (map.count(r) > 0) {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }
            
            // the remainder is first seen
            // remember the current position for it
            map[r] = res.size();
            
            r *= 10;
            
            // append the quotient digit
            res += to_string(r / denominator);
        }
        
        return res;
    }
};

int main() {
    Solution s;
    cout << s.fractionToDecimal(4,13) << endl;
}