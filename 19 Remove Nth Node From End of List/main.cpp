#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head, *second = head, *previous = head;
        
        while (n != 0) {
            first = first->next;
            n--;
        }
        
        while (first != NULL) {
            first = first->next;
            previous = second;
            second = second->next;
        }
        
        if (second->next != NULL) {
            ListNode *t = second->next;
            second->val = t->val;
            second->next = t->next;
            delete t;
            t = NULL;
        } else if (head == second) {
            delete head;
            second = NULL;
            head = NULL;
        } else {
            previous->next = NULL;
            delete second;
            second = NULL;
        }
        
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    Solution s;
    head = s.removeNthFromEnd(head, 1);
    ListNode *t = head;
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    delete head;
    return 0;
}
