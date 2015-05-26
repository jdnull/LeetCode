#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryOver = 0;
        vector<int>::reverse_iterator rit = digits.rbegin();
        if (*rit + 1 > 9) {
            carryOver = 1;
            *rit = 0;
        } else {
            *rit += 1;
        }
        for (rit++; rit != digits.rend(); rit++) {
            if (*rit + carryOver > 9) {
                carryOver = 1;
                *rit = 0;
            } else {
                *rit += carryOver;
                carryOver = 0;
            }
        }
        if (carryOver == 0) {
            return digits;
        } else {
            vector<int> v;
            v.push_back(1);
            for (vector<int>::iterator it = digits.begin(); it != digits.end(); it++) {
                v.push_back(*it);
            }
            return v;
        }
    }
};

#define COUNT 3
int main() {
    int a[COUNT] = {9,9,9};
    vector<int> nums(a, &a[COUNT]);
    Solution s;
    vector<int> v = s.plusOne(nums);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    
    return 0;
}
