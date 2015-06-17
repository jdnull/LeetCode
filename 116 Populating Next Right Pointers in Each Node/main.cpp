#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // not my code,
//    void connect(TreeLinkNode *root) {
//        if (root == NULL) {
//            return;
//        }
//        
//        TreeLinkNode *p = root;
//        TreeLinkNode *first = NULL;
//        
//        while (p) {
//            if (!first) { // mark the first node of next level
//                first = p->left;
//            }
//            
//            if (p->left) {
//                p->left->next = p->right;
//            } else { // p is leaf node
//                break;
//            }
//            
//            if (p->next) {
//                p->right->next = p->next->left;
//                p = p->next;
//                continue;
//            } else { // p is the right most node
//                p = first;
//                first = NULL;
//            }
//        }
//    }
    
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        connectLeftRight(root);
        connectRightLeft(root);
    }
    
    void connectLeftRight(TreeLinkNode *root) {
        if (root->left == NULL || root->right == NULL) {
            return;
        }
        root->left->next = root->right;
        connectLeftRight(root->left);
        connectLeftRight(root->right);
    }
    
    void connectRightLeft(TreeLinkNode *root) {
        if (root->next != NULL) {
            if (root->right && root->next->left) {
                root->right->next = root->next->left;
            }
        }
        if (root->left) {
            connectRightLeft(root->left);
        }
        if (root->right) {
            connectRightLeft(root->right);
        }
    }
};

int main() {
    
    
    return 0;
}
