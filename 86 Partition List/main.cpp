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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }
        
        ListNode left = ListNode(0);
        ListNode right = ListNode(0);
        ListNode *leftTail = &left, *rightTail = &right;
        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                leftTail->next = p;
                p = p->next;
                leftTail = leftTail->next;
                leftTail->next = NULL;
            } else {
                rightTail->next = p;
                p = p->next;
                rightTail = rightTail->next;
                rightTail->next = NULL;
            }
        }
        
        leftTail->next = right.next;
        return left.next;
    }
};

int main() {
    return 0;
}
