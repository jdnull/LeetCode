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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        
        ListNode *a = headA, *b = headB;
        int aLen = 0, bLen = 0;
        while (a) {
            aLen++;
            a = a->next;
        }
        while (b) {
            bLen++;
            b = b->next;
        }
        
        a = headA, b = headB;
        if (aLen > bLen) {
            while (aLen != bLen) {
                a = a->next;
                bLen++;
            }
        } else {
            while (aLen != bLen) {
                b = b->next;
                aLen++;
            }
        }
        
        while (true) {
            if (a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
    }
};

int main() {
    return 0;
}
