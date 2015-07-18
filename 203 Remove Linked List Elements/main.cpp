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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        
        ListNode *prev = &dummy;
        ListNode *curr = head;
        while (curr) {
            while (curr && curr->val == val) {
                ListNode *t = curr->next;
                delete curr;
                curr = t;
            }
            prev->next = curr;
            if (curr) {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(2);
    a->next = b;
    b->next = c;
    
    Solution s;
    ListNode *x = s.removeElements(a, 2);
    ListNode *p = x;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
}