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
    void deleteNode(ListNode* node) {
        ListNode *p = node;
        while (p) {
            if (!p->next->next) {
                p->val = p->next->val;
                delete p->next;
                p->next = NULL;
                break;
            } else {
                p->val = p->next->val;
                p = p->next;
            }
        }
    }
};

int main() {
    
}