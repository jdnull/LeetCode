#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head, *p;
        head = p = new ListNode(0);
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && (l2 == NULL || l1->val < l2->val)) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return head->next;
    }
};

int main() {
    
    return 0;
}
