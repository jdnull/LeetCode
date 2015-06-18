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
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        
        TreeLinkNode *p = root;
        TreeLinkNode *first = NULL;
        TreeLinkNode *last = NULL;
        while (p) {
            if (!first) {
                if (p->left) {
                    first = p->left;
                } else if(p->right) {
                    first = p->right;
                }
            }
            
            if (p->left) {
                if (last) {
                    last->next = p->left;
                }
                last = p->left;
            }
            
            if (p->right) {
                if (last) {
                    last->next = p->right;
                }
                last = p->right;
            }
            
            if (p->next) {
                p = p->next;
            } else {
                p = first;
                first = NULL;
                last = NULL;
            }
        }
    }
};

int main() {
    
    
    return 0;
}
