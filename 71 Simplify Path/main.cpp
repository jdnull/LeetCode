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
    string simplifyPath(string path) {
        vector<string> v = split(path);
        stack<string> st;
        
        for (int i = 0; i < v.size(); i++) {
            if (v[i].compare(".") == 0) {
                continue;
            } else if (v[i].compare("..") == 0) {
                if (st.empty()) {
                    continue;
                } else {
                    st.pop();
                }
            } else {
                st.push(v[i]);
            }
        }
        
        string ret = "";
        while (!st.empty()) {
            ret = "/" + st.top() + ret;
            st.pop();
        }
        
        return ret.compare("") == 0 ? "/" : ret;
    }
    
    vector<string> split(string path) {
        vector<string> v;
        string temp = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (temp.compare("") != 0) {
                    v.push_back(temp);
                }
                temp = "";
            } else {
                temp += path[i];
            }
        }
        if (temp.compare("") != 0) {
            v.push_back(temp);
        }
        return v;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/home//foo/") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/..") << endl;
}