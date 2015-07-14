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
//    bool isIsomorphic(string s, string t) {
//        string ss = getIsomorphic(s);
//        string tt = getIsomorphic(t);
//        
//        return ss.compare(tt) == 0 ? true : false;
//    }
//    
//    string getIsomorphic(string s) {
//        map<char, int> m;
//        string isomorphic = "";
//        int count = 0;
//        for (int i = 0; i < s.length(); i++) {
//            if (m.find(s[i]) != m.end()) {
//                isomorphic += m[s[i]] + '0';
//            } else {
//                m[s[i]] = count;
//                isomorphic += count + '0';
//                count++;
//            }
//        }
//        return isomorphic;
//    }
    
    // not my code
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    
}