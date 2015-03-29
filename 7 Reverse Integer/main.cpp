#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long num = abs((long)x);
        long new_num = 0;
        while(num) {
            new_num = new_num*10 + num%10;
            num /= 10;
        }
        
        if (new_num > INT_MAX) {
            return 0;
        }
        return (x<0 ? -1*new_num : new_num);
    }
};

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
    
    return 0;
}
