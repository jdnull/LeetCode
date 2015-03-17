#include <iostream>
#include <vector>
#include <map>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode *a = l1, *b = l2, *pre = NULL;
        int addToHigh = 0;
        while(a != NULL && b != NULL) {
            int t = a->val + b->val + addToHigh;
            a->val = t % 10;
            if (t > 9) {
                addToHigh = 1;
            } else {
                addToHigh = 0;
            }
            pre = a;
            a = a->next;
            b = b->next;
        }
        
        if (a != NULL) {
            while (addToHigh != 0 && a != NULL) {
                int t = a->val + addToHigh;
                a->val = t % 10;
                if (t > 9) {
                    addToHigh = 1;
                } else {
                    addToHigh = 0;
                }
                pre = a;
                a = a->next;
            }
        }
        
        if (b != NULL) {
            pre->next = b;
            while (addToHigh != 0 && b != NULL) {
                int t = b->val + addToHigh;
                b->val = t % 10;
                if (t > 9) {
                    addToHigh = 1;
                } else {
                    addToHigh = 0;
                }
                pre = b;
                b = b->next;
            }
        }
        
        if (addToHigh > 0) {
            pre->next = new ListNode(1);
        }
        
        return l1;
    }
};

int main() {
//    Solution s;
//    int a[5] = {-1,-2,-3,-4,-5};
//    vector<int> input(&a[0], &a[5]);
//    vector<int> v = s.twoSum(input, -8);
//    cout << v[0] << " " << v[1] << endl;
    return 0;
}
