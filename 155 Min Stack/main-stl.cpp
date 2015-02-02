//
//  MinStack-stl.h
//  MinStack
//
//  Created by JD on 14/11/13.
//  Copyright (c) 2014年 JD. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> min;
    
public:
    void push(int x) {
        st.push(x);
        if (min.empty() || x < min.top()) {
            min.push(x);
        } else {
            min.push(min.top());
        }
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

int main(int argc, const char * argv[]) {
    MinStack ms;
    ms.push(3);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.push(1);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.push(2);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    return 0;
}

