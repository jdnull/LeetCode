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
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (i < s.length() && !isAlpha(s[i])) {
                i++;
            }
            if (i >= j) break;
            while (j > -1 && !isAlpha(s[j])) {
                j--;
            }
            if (!isEqual(s[i], s[j])) {
                return false;
            } else {
                i++, j--;
                
            }
        }
        return true;
    }
    
    bool isEqual(char a, char b) {
        if (a == b || a + 32 == b || a == b + 32) {
            return true;
        }
        return false;
    }
    
    bool isAlpha(char a) {
        if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9')) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
}