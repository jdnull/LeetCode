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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    ListNode p = ListNode(1);
    Solution s;
    cout << s.hasCycle(&p) << endl;
    return 0;
}
