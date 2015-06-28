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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int reverseLen = n - m + 1;
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        
        ListNode *pre = &dummy;
        while (m != 1) {
            pre = pre->next;
            m--;
        }
        
        ListNode *tail = pre->next;
        ListNode *p = pre->next;
        pre->next = NULL;
        while (reverseLen) {
            ListNode *q = p->next;
            p->next = pre->next;
            pre->next = p;
            p = q;
            reverseLen--;
        }
        
        tail->next = p;
        
        return dummy.next;
    }
};

int main() {
    return 0;
}
