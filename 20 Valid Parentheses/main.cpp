#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (!st.empty() && s[i] == ']') {
                if (st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (!st.empty() && s[i] == '}') {
                if (st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(s[i]);
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    
    return 0;
}
