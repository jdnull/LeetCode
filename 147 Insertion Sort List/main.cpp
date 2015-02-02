/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) return head;
        
        ListNode *myHead = new ListNode(0);
        myHead->next = head;
        ListNode *p = head->next, *q, *t, *temp;
        head->next = NULL;
        
        while(p != NULL) {
            temp = p->next;
            p->next = NULL;
            q = myHead->next;
            t = myHead;
            while(q != NULL) {
                if(p->val > q->val) {
                    if(q->next == NULL) {
                        q->next = p;
                        break;
                    } else {
                        q = q->next;
                        t = t->next;
                    }
                } else {
                    t->next = p;
                    p->next = q;
                    break;
                }
            }
            p = temp;
        }
        
        head = myHead->next;
        delete myHead;
        return head;
    }
};