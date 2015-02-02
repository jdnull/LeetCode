//
//  MinStack.h
//  MinStack
//
//  Created by JD on 14/11/12.
//  Copyright (c) 2014年 JD. All rights reserved.
//

#include <iostream>

class Node {
public:
    int val;
    int min;
    Node* next;
    
    Node(int x) {
        val = x;
    }
};

class MinStack {
private:
    Node* topNode;
    
public:
    MinStack() {
        topNode = NULL;
    }
    
    void push(int x) {
        Node* n = new Node(x);
        n->next = topNode;
        if (topNode == NULL || x < topNode->min) {
            n->min = x;
        } else {
            n->min = topNode->min;
        }
        topNode = n;
    }
    
    void pop() {
        if (topNode != NULL) {
            Node* n = topNode;
            topNode = n->next;
            delete n;
        }
    }
    
    int top() {
        return topNode->val;
    }
    
    int getMin() {
        return topNode->min;
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

