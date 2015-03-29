#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        vector<int> v;
        while (x != 0) {
            v.push_back(x%10);
            x = x / 10;
        }
        
        for (int i = 0; i < v.size() / 2; i++) {
            if (v[i] != v[v.size()-1-i]) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(1221) << endl;
    
    return 0;
}
