#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return head;
        }
        
        RandomListNode *p = head;
        while (p) {
            RandomListNode *t = new RandomListNode(p->label);
            t->next = p->next;
            t->random = p->random;
            p->next = t;
            p = t->next;
        }
        
        p = head->next;
        while (p) {
            if (p->random) {
                p->random = p->random->next;
            }
            if (p->next == NULL) {
                break;
            }
            p = p->next->next;
        }
        
        p = head;
        RandomListNode *newP = head->next, *newHead = head->next;
        while (newP) {
            p->next = newP->next;
            p = p->next;
            if (p == NULL) {
                break;
            }
            newP->next = p->next;
            newP = newP->next;
        }
        
        return newHead;
    }
};

int main() {
    return 0;
}
