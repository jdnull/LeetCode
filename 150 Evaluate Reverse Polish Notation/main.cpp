class Solution {
public:
    int pop(vector<int> &st) {
    int last = st[st.size()-1];
    st.pop_back();
    return last;
}

int evalRPN(vector<string> &tokens) {
    vector<int> st;
    for(vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++){
        int a,b;
        if(*iter == "+") {
            b = pop(st);
            a = pop(st);
            a = a + b;
            st.push_back(a);
        }
        else if(*iter == "-") {
            b = pop(st);
            a = pop(st);
            a = a - b;
            st.push_back(a);
        }
        else if(*iter == "*") {
            b = pop(st);
            a = pop(st);
            a = a * b;
            st.push_back(a);
        }
        else if(*iter == "/") {
            b = pop(st);
            a = pop(st);
            a = a / b;
            st.push_back(a);
        }
        else {
            st.push_back(atoi((*iter).c_str()));
        }
    }
    return pop(st);
}
};