#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
/////////////////////////////////////////////////////////////////////////////
    // this method time limit exceeded, O( n^(logn) )
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if(lists.size() < 1) return NULL;
//        return mergeKLists(lists, 0, lists.size()-1);
//    }
//    
//    ListNode* mergeKLists(vector<ListNode*> lists, int begin, int end) {
//        int k = end - begin + 1;
//        
//        if(k == 1) {
//            return lists[begin];
//        }
//        
//        if(k == 2) {
//            return merge2Lists(lists[begin], lists[end]);
//        }
//        
//        int mid = k / 2;
//        ListNode* left = mergeKLists(lists, begin, begin+mid);
//        ListNode* right = mergeKLists(lists, begin+mid+1, end);
//        
//        return merge2Lists(left, right);
//    }
//    
//    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
//        if(l1 == NULL) return l2;
//        if(l2 == NULL) return l1;
//        
//        ListNode *p1 = l1, *p2 = l2;
//        ListNode *head = NULL;
//        if(p1->val < p2->val) {
//            head = p1;
//            p1 = p1->next;
//        } else {
//            head = p2;
//            p2 = p2->next;
//        }
//        head->next = NULL;
//        ListNode *t = head;
//        while(p1 != NULL && p2 != NULL) {
//            if(p1->val < p2->val) {
//                t->next = p1;
//                p1 = p1->next;
//                t = t->next;
//                t->next = NULL;
//            } else {
//                t->next = p2;
//                p2 = p2->next;
//                t = t->next;
//                t->next = NULL;
//            }
//        }
//        if(p1 != NULL) {
//            t->next = p1;
//        }
//        if(p2 != NULL) {
//            t->next = p2;
//        }
//        return head;
//    }
/////////////////////////////////////////////////////////////////////////////
    
/////////////////////////////////////////////////////////////////////////////
    // less time consume method, not my code
//    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
//        if (NULL == l1) return l2;
//        else if (NULL == l2) return l1;
//        if (l1->val <= l2->val) {
//            l1->next = mergeTwoLists(l1->next, l2);
//            return l1;
//        }
//        else {
//            l2->next = mergeTwoLists(l1, l2->next);
//            return l2;
//        }
//    }
//    ListNode *mergeKLists(vector<ListNode *> &lists) {
//        if (lists.empty()) return NULL;
//        int len = lists.size();
//        while (len > 1) {
//            for (int i = 0; i < len / 2; ++i) {
//                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
//            }
//            len = (len + 1) / 2;
//        }
//        
//        return lists.front();
//    }
/////////////////////////////////////////////////////////////////////////////
    
    // time complexity, O(nlogn)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL;
        while (lists.size() != 1) {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin(), lists.begin()+2);
        }
        return lists[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = NULL;
        if(p1->val < p2->val) {
            head = p1;
            p1 = p1->next;
        } else {
            head = p2;
            p2 = p2->next;
        }
        head->next = NULL;
        ListNode *t = head;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                t->next = p1;
                p1 = p1->next;
                t = t->next;
                t->next = NULL;
            } else {
                t->next = p2;
                p2 = p2->next;
                t = t->next;
                t->next = NULL;
            }
        }
        if(p1 != NULL) {
            t->next = p1;
        }
        if(p2 != NULL) {
            t->next = p2;
        }
        return head;
    }
};

ListNode* initList(int* a, int n) {
    if (n < 1) {
        return NULL;
    }
    
    ListNode *head = new ListNode(a[0]);
    ListNode *t = head;
    for (int i = 1; i < n; i++) {
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    return head;
}

void deleteList(ListNode *head) {
    ListNode *t = head;
    ListNode *p;
    while (t != NULL) {
        p = t->next;
        delete t;
        t = NULL;
        t = p;
    }
}

int main() {
    vector<ListNode*> lists;
    
    int a[7] = {-10,-9,-9,-3,-1,-1,0};
    lists.push_back(initList(a, 7));
    
    int b[1] = {-5};
    lists.push_back(initList(b, 1));
    
    int c[1] = {4};
    lists.push_back(initList(c, 1));
    
    int d[1] = {-8};
    lists.push_back(initList(d, 1));
    
    int e[0] = {};
    lists.push_back(initList(e, 0));
    
    int f[7] = {-9,-6,-5,-4,-2,2,3};
    lists.push_back(initList(f, 7));
    
    int g[5] = {-3,-3,-2,-1,0};
    lists.push_back(initList(g, 5));
    
    Solution s;
    ListNode *mergeList = s.mergeKLists(lists);
    ListNode *t = mergeList;
    while (t != NULL) {
        cout << t->val << "->";
        t = t->next;
    }
    
    deleteList(mergeList);
    
    return 0;
}
