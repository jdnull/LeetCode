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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseFirstKNode(head, k);
    }
    
    ListNode* reverseFirstKNode(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        
        int t = k;
        ListNode* subListHead = head;
        while (t != 0) {
            t--;
            subListHead = subListHead->next;
            if (subListHead == NULL && t != 0) {
                return head;
            }
        }
        
        t = k;
        ListNode *p = head;
        ListNode *newHead = head->next;
        p->next = NULL;
        while (t != 1) {
            t--;
            ListNode* tempNode = newHead->next;
            newHead->next = p;
            p = newHead;
            newHead = tempNode;
        }
        
        head->next = reverseFirstKNode(subListHead, k);
        return p;
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

#define COUNT 2
int main() {
    vector<ListNode*> lists;
    
    int a[COUNT] = {1,2};
    ListNode *t = initList(a, COUNT);
    
    Solution s;
    ListNode *reversedList = s.reverseKGroup(t,2);
    t = reversedList;
    while (t != NULL) {
        cout << t->val << "->";
        t = t->next;
    }
    cout << endl;
    
    deleteList(reversedList);
    
    return 0;
}
