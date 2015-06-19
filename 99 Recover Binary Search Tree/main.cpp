#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // not my code, Morris Traversal, much slower
    /*
         Inorder Traversal（should get ascending seq.）：Analysis:
         case A: If 2 near nodes swapped，then there will be just 1 Inversion Pair.
         case B: If 2 nodes not near swapped，then there will be 2 Inversion Pairs.
         Weather case A or case B, swap the max-value and the min-value of the Inversion Pair(s).
     */
    void recoverTree(TreeNode *root) {
        TreeNode *cur, *pre, *node1, *node2;  // node1, node2: Record 2 near nodes
        TreeNode *first, *second;  // Record 2 swapping nodes
        node1 = node2 = first = NULL;
        cur = root;
        while(cur) {
            if(cur->left == NULL) {
                if(node1 == NULL) node1 = cur;
                else if(node2 == NULL) node2 = cur;
                else { node1 = node2; node2 = cur;}
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right && pre->right != cur) pre = pre->right;
                if(pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    pre->right = NULL;
                    if(node2 == NULL) node2 = cur;
                    else {node1 = node2; node2 = cur;}
                    cur = cur->right;
                }
            }
            if(node1 && node2 && node1->val > node2->val) {
                
                if(first == NULL)  first = node1;
                second = node2;
            }
        }
        /* already learn that there exist 2 nodes swapped.*/
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
    
    // not my code, not O(1) space
    /*
        Note: 
        1. Given a sequence {1, 4, 3, 7, 9}, you find pair 4(!<=)3, swap this pair and sequence is in order.
        2. Given a sequence {1, 9, 4, 5, 3, 10}, you get first pair 9(!<=)4 and second pair 5(!<=)3, swap pair 9(!<=)3 and sequence is in order.
        3. Given a sequence, only in two above (general) cases, that you can just swap one pair numbers to convert an unordered sequence into ordered.
        4. You can tranverse BST inorder to get above sequence.
     */
//    void recover(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b) {
//        if (root)
//        {
//            recover(root->left, pre, a, b);
//            
//            if (root->val < pre->val)
//            {
//                if (!a) a = pre; //a should change once.
//                b = root; //b could change twice.
//            }
//            pre = root;
//            
//            recover(root->right, pre, a, b);
//        }
//    }
//    void recoverTree(TreeNode *root) {
//        if (!root) return;
//        
//        TreeNode p(numeric_limits<int>::min());
//        TreeNode *a, *b, *pre;
//        a = b = NULL;
//        pre = &p;
//        recover(root, pre, a, b);
//        if (a && b)
//        {
//            swap(a->val, b->val);
//        }
//        return;
//    }
};

int main() {
    
    
    return 0;
}
