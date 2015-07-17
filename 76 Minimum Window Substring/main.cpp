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
    // Time Limit Exceeded
//    string minWindow(string s, string t) {
//        unordered_map<string, int> retMap;
//        unordered_map<char, int> m;
//        resetMap(m, t);
//        
//        int start = 0, end = 0;
//        for (int i = 0 ; i < s.length(); i++) {
//            if (m.find(s[i]) != m.end()) {
//                m[s[i]]++;
//                if (checkContain(m)) {
//                    end = i;
//                    int j = start;
//                    for (; j <= end; j++) {
//                        if (m.find(s[j]) != m.end()) {
//                            m[s[j]]--;
//                            if (m[s[j]] == 0) {
//                                break;
//                            }
//                        }
//                    }
//                    start = j;
//                    string tempStr = s.substr(start, end-start+1);
//                    retMap[tempStr] = end-start+1;
//                    i = start;
//                    start++;
//                    resetMap(m, t);
//                }
//            }
//        }
//        
//        string ret = "";
//        int len = s.length();
//        for (unordered_map<string, int>::iterator it = retMap.begin(); it != retMap.end(); it++) {
//            if (it->second < len) {
//                ret = it->first;
//                len = it->second;
//            }
//        }
//        return ret;
//    }
//    
//    void resetMap(unordered_map<char, int>& m, string t) {
//        for (int i = 0; i < t.length(); i++) {
//            m[t[i]] = 0;
//        }
//    }
//    
//    bool checkContain(unordered_map<char, int>& m) {
//        for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
//            if (it->second == 0) {
//                return false;
//            }
//        }
//        return true;
//    }
    
    // not my code
    string minWindow(string S, string T) {
        if (S.empty() || T.empty())
        {
            return "";
        }
        int count = T.size();
        int require[128] = {0};
        bool chSet[128] = {false};
        for (int i = 0; i < count; ++i)
        {
            require[T[i]]++;
            chSet[T[i]] = true;
        }
        int i = -1;
        int j = 0;
        int minLen = INT_MAX;
        int minIdx = 0;
        while (i < (int)S.size() && j < (int)S.size())
        {
            if (count)
            {
                i++;
                require[S[i]]--;
                if (chSet[S[i]] && require[S[i]] >= 0)
                {
                    count--;
                }
            }
            else
            {
                if (minLen > i - j + 1)
                {
                    minLen = i - j + 1;
                    minIdx = j;
                }
                require[S[j]]++;
                if (chSet[S[j]] && require[S[j]] > 0)
                {
                    count++;
                }
                j++;
            }
        }
        if (minLen == INT_MAX)
        {
            return "";
        }
        return S.substr(minIdx, minLen);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution ss;
    cout << ss.minWindow(s, t) << endl;
}