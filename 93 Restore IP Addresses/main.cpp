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
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if (s.length() < 4 || s.length() > 12) return v;
        helper(v, s, 0, 0);
        return v;
    }
    
    void helper(vector<string>& v, string& s, int countDot, int begin) {
        if (countDot == 3) {
            if (isValidIP(s)) {
                v.push_back(s);
            }
            return;
        }
        
        for (int i = begin; i < s.length()-1; i++) { // can do some clipping here
            s.insert(i+1, ".");
            helper(v, s, countDot+1, i+2);
            s.erase(i+1, 1);
        }
    }
    
    bool isValidIP(string s) {
        stringstream ss(s);
        string temp;
        while (getline(ss, temp, '.')) {
            int t = stoi(temp);
            if (t < 0 || t > 255
                || (temp[0] == '0' && t != 0) // get rid of 0.1.0.010
                || (temp.length() > 1 && t == 0)) { // get rid of 0.1.00.10
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> v = s.restoreIpAddresses("010010");
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}