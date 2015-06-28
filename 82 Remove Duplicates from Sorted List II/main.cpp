#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *pre = &dummy, *p = pre->next;
        
        while (p && p->next) {
            if (p->val != p->next->val) {
                pre = p;
                p = p->next;
            } else {
                while (p->next && p->val == p->next->val) {
                    ListNode *t = p->next->next;
                    delete p->next;
                    p->next = t;
                }
                pre->next = p->next;
                delete p;
                
                p = pre->next;
            }
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(2);
    ListNode *d = new ListNode(2);
    a->next = b;
    b->next = c;
    c->next = d;
    Solution s;
    s.deleteDuplicates(a);
    return 0;
}
