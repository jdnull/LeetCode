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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        int circleLength = 0;
        bool hasCircle = false;
        
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            circleLength++;
            if (fast == slow) {
                hasCircle = true;
                break;
            }
        }
        
        if (!hasCircle) {
            return NULL;
        }
        
        fast = head, slow = head;
        while (circleLength) {
            fast = fast->next;
            circleLength--;
        }
        
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

int main() {
    return 0;
}
