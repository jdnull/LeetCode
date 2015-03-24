#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        string s;
        map<string, int> anagram;
        vector<string> res;
        for (int i = 0; i < strs.size(); ++i) {
            s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram[s] = i;
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};

int main() {
    string arr[5] = {"tea","and","ate","eat","den"};
    vector<string> strs(arr, &arr[5]);
    Solution s;
    vector<string> res = s.anagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
