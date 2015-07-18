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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
//    // Iteratively
//    ListNode* reverseList(ListNode* head) {
//        if (!head) {
//            return head;
//        }
//        
//        ListNode *p = head->next;
//        head->next = NULL;
//        while (p) {
//            ListNode *q = p->next;
//            p->next = head;
//            head = p;
//            p = q;
//        }
//        
//        return head;
//    }
    
    // Recursively
    ListNode *tail;
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        return reverseListHelper(head);
    }
    
    ListNode* reverseListHelper(ListNode* head) {
        if (!head->next) {
            tail = head;
            return head;
        }
        
        ListNode *p = reverseListHelper(head->next);
        head->next = NULL;
        tail->next = head;
        tail = head;
        head = p;
        
        return head;
    }
};

int main() {
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(1);
//    ListNode *c = new ListNode(2);
    a->next = b;
//    b->next = c;
    
    Solution s;
    ListNode *x = s.reverseList(a);
    ListNode *p = x;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
}