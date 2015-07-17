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
    // Memory Limit Exceeded
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> indices;
//        if (words.empty() || words[0].length() * words.size() > s.length()) {
//            return indices;
//        }
//        
//        vector<vector<string>> concatenations;
//        getConcatenations(concatenations, words, 0);
//        
//        unordered_map<string, int> m;
//        for (int i = 0; i < concatenations.size(); i++) {
//            string tempStr = "";
//            for (int j = 0; j < concatenations[i].size(); j++) {
//                tempStr += concatenations[i][j];
//            }
//            m[tempStr] = 0;
//        }
//        
//        int concatLen = words[0].length() * words.size();
//        for (int i = 0; i < s.length(); i++) {
//            string tempStr = s.substr(i, concatLen);
//            if (m.find(tempStr) != m.end()) {
//                indices.push_back(i);
//            }
//        }
//        
//        return indices;
//    }
//    
//    void getConcatenations(vector<vector<string>>& concatenations, vector<string>& words, int level) {
//        if (level >= words.size()) {
//            concatenations.push_back(words);
//            return;
//        }
//        
//        for (int i = level; i < words.size(); i++) {
//            swap(words[level], words[i]);
//            getConcatenations(concatenations, words, level+1);
//            swap(words[level], words[i]);
//        }
//    }
    
    // not my code, too slow
//    vector<int> findSubstring(string s, vector<string>& words) {
//        unordered_map<string, int> counts;
//        for (string word : words)
//            counts[word]++;
//        int n = s.length(), num = words.size(), len = words[0].length();
//        vector<int> indexes;
//        for (int i = 0; i < n - num * len + 1; i++) {
//            unordered_map<string, int> seen;
//            int j = 0;
//            for (; j < num; j++) {
//                string word = s.substr(i + j * len, len);
//                if (counts.find(word) != counts.end()) {
//                    seen[word]++;
//                    if (seen[word] > counts[word])
//                        break;
//                }
//                else break;
//            }
//            if (j == num) indexes.push_back(i);
//        }
//        return indexes;
//    }
    
    // not my code
    // travel all the words combinations to maintain a window
    // there are wl(word len) times travel
    // each time, n/wl words, mostly 2 times travel for each word
    // one left side of the window, the other right side of the window
    // so, time complexity O(wl * 2 * N/wl) = O(2N)
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = S.size(), cnt = L.size();
        if (n <= 0 || cnt <= 0) return ans;
        
        // init word occurence
        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i) dict[L[i]]++;
        
        // travel all sub string combinations
        int wl = L[0].size();
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl) {
                string str = S.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str])
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = S.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[S.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");
    
    Solution ss;
    vector<int> v = ss.findSubstring(s, words);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}