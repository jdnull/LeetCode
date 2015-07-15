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
    // Memory limit exceed
//    vector<string> findRepeatedDnaSequences(string s) {
//        unordered_map<string, int> m;
//        for (int i = 0; i < s.length(); i++) {
//            string p = s.substr(i, 10);
//            if (m.find(p) != m.end()) {
//                if (m[p] == 2) {
//                    continue;
//                } else {
//                    m[p]++;
//                }
//            } else {
//                m[p] = 1;
//            }
//        }
//        
//        vector<string> v;
//        for (unordered_map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
//            if (it->second == 2) {
//                v.push_back(it->first);
//            }
//        }
//        
//        return v;
//    }
    
    //not my code
    /*
         There are only four possible character A, C, G, and T, but I want to use 3 bits per letter instead of 2.
         
         Why? It's easier to code.
         
         A is 0x41, C is 0x43, G is 0x47, T is 0x54. Still don't see it? Let me write it in octal.
         
         A is 0101, C is 0103, G is 0107, T is 0124. The last digit in octal are different for all four letters. That's all we need!
         
         We can simply use s[i] & 7 to get the last digit which are just the last 3 bits
     */
    // a bit slow
//    vector<string> findRepeatedDnaSequences(string s) {
//        unordered_map<int, bool> m;
//        vector<string> r;
//        for (int t = 0, i = 0; i < s.size(); i++) {
//            t = t << 3 & 0x3FFFFFFF | s[i] & 7;
//            if (m.find(t) != m.end()) {
//                if (m[t]) {
//                    r.push_back(s.substr(i - 9, 10));
//                    m[t] = false;
//                }
//            } else {
//                m[t] = true;
//            }
//        }
//        return r;
//    }
    
    // not my code, fastest!!!
    // but i don't understand
    vector<string> findRepeatedDnaSequences(string s) {
        char  hashMap[1048576] = {0};
        vector<string> ans;
        int len = s.size(),hashNum = 0;
        if (len < 11) return ans;
        for (int i = 0;i < 9;++i)
            hashNum = hashNum << 2 | (s[i] - 'A' + 1) % 5;
        for (int i = 9;i < len;++i)
            if (hashMap[hashNum = (hashNum << 2 | (s[i] - 'A' + 1) % 5) & 0xfffff]++ == 1)
                ans.push_back(s.substr(i-9,10));
        return ans;
    }
};

int main() {
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution s;
    vector<string> v = s.findRepeatedDnaSequences(str);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}