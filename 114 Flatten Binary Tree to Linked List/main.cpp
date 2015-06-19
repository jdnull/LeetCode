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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        if (root->left) {
            flatten(root->left);
        }
        if (root->right) {
            flatten(root->right);
        }
        
        if (root->left) {
            TreeNode *rightMost = root->left;
            while (rightMost && rightMost->right) {
                rightMost = rightMost->right;
            }
            
            rightMost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        } else {
            return;
        }
    }
};

int main() {
    
    
    return 0;
}
