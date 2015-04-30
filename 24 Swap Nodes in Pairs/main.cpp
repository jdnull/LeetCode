#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *falseHead = new ListNode(0);
        falseHead->next = head;
        
        ListNode *t = falseHead;
        ListNode *p = head;
        ListNode *q = head->next;
        
        while (p != NULL && q != NULL) {
            p->next = q->next;
            q->next = p;
            t->next = q;
            
            t = p;
            if (t == NULL) {
                break;
            }
            p = t->next;
            if (p != NULL) {
                q = p->next;
            }
        }
        
        head = falseHead->next;
        
        delete falseHead;
        
        return head;
    }
};

ListNode* initList(int* a, int n) {
    if (n < 1) {
        return NULL;
    }
    
    ListNode *head = new ListNode(a[0]);
    ListNode *t = head;
    for (int i = 1; i < n; i++) {
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    return head;
}

void deleteList(ListNode *head) {
    ListNode *t = head;
    ListNode *p;
    while (t != NULL) {
        p = t->next;
        delete t;
        t = NULL;
        t = p;
    }
}

int main() {
    vector<ListNode*> lists;
    
    int a[4] = {1,2,3,4};
    ListNode *t = initList(a, 4);
    
    Solution s;
    ListNode *swapped = s.swapPairs(t);
    t = swapped;
    while (t != NULL) {
        cout << t->val << "->";
        t = t->next;
    }
    cout << endl;
    
    deleteList(swapped);
    
    return 0;
}
