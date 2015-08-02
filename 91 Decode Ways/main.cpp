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
    // not my code, DP
    int numDecodings(string s) {
        // empty string or leading zero means no way
        if (!s.size() || s.front() == '0') return 0;
        
        // r1 and r2 store ways of the last and the last of the last
        int r1 = 1, r2 = 1;
        
        for (int i = 1; i < s.size(); i++) {
            // zero voids ways of the last because zero cannot be used separately
            if (s[i] == '0') r1 = 0;
            
            // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                r1 = r2 + r1;
                r2 = r1 - r2;
            }
            
            // one-digit letter, no new way added
            else {
                r2 = r1;
            }
        }
        
        return r1;
    }
    
    // my code, backtracking, time limit exceed
//    int numDecodings(string s) {
//        vector<int> v;
//        vector<vector<int>> vv;
//        helper(vv, v, 0, s);
//        return vv.size();
//    }
//    
//    void helper(vector<vector<int>>& vv, vector<int> v, int sum, string s) {
//        if (sum == s.length()) {
//            if (isValidDecode(v, s)) {
//                vv.push_back(v);
//            }
//            return;
//        }
//        
//        for (int i = 1; i <= 2; i++) {
//            if (sum + i <= s.length()) {
//                v.push_back(i);
//                helper(vv, v, sum+i, s);
//                v.pop_back();
//            }
//        }
//    }
//    
//    bool isValidDecode(vector<int> v, string s) {
//        int index = 0;
//        for (int i = 0; i < v.size(); i++) {
//            string temp = s.substr(index, v[i]);
//            if (stoi(temp) < 1 || stoi(temp) > 26) {
//                return false;
//            }
//            index += v[i];
//        }
//        return true;
//    }
};

int main() {
    Solution s;
    cout << s.numDecodings("12") << endl;
//    cout << s.numDecodings("6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155") << endl;
}