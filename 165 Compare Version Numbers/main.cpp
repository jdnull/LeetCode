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
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        
        vector<int>::iterator it1 = v1.begin(), it2 = v2.begin();
        
        while (it1 != v1.end() && it2 != v2.end()) {
            if (*it1 == *it2) {
                it1++, it2++;
            } else if (*it1 > *it2) {
                return 1;
            } else {
                return -1;
            }
        }
        
        // 1.0 == 1
        while (it1 != v1.end() && *it1 == 0) {
            it1++;
        }
        while (it2 != v2.end() && *it2 == 0) {
            it2++;
        }
        
        if (it1 != v1.end()) {
            return 1;
        }
        
        if (it2 != v2.end()) {
            return -1;
        }
        
        return 0;
    }
    
    vector<int> split(string version) {
        vector<int> v;
        string temp = "";
        for (int i = 0; i < version.length(); i++) {
            if (version[i] == '.') {
                v.push_back(stringToInt(temp));
                temp = "";
            } else {
                temp += version[i];
            }
        }
        v.push_back(stringToInt(temp));
        return v;
    }
    
    int stringToInt(string s) {
        stringstream ss;
        ss << s;
        int ret;
        ss >> ret;
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.0", "1") << endl;
}