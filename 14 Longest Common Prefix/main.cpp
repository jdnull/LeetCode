#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string findLCP(string s1, string s2) {
        int len = min(s1.length(), s2.length());
        int i = 0;
        for (; i < len; i++) {
            if (s1[i] != s2[i]) {
                break;
            }
        }
        return s1.substr(0,i);
    }
    
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        
        string ret = findLCP(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++) {
            ret = findLCP(ret, strs[i]);
        }
        
        return ret;
    }
};

#define COUNT 3

int main() {
    string a[COUNT] = {"aba", "abb", "a"};
    vector<string> strs(a, &a[COUNT]);
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    
    return 0;
}
