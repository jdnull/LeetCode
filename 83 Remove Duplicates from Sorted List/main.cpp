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
        ListNode *p = head, *q;
        while (p) {
            q = p->next;
            while (q && q->val == p->val) {
                ListNode *t = q->next;
                delete q;
                q = t;
            }
            p->next = q;
            p = q;
        }
        return head;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(1);
    a->next = b;
    Solution s;
    s.deleteDuplicates(a);
    return 0;
}
