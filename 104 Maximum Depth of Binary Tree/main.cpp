#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // my code, too slow
//    int maxDepth(TreeNode* root) {
//        return dfs(root);
//    }
//    
//    int dfs(TreeNode* root) {
//        if(root == NULL) {
//            return 0;
//        }
//        int leftDepth = dfs(root->left);
//        int rightDepth = dfs(root->right);
//        return max(leftDepth, rightDepth) + 1;
//    }
    
    // simplest code
//    int maxDepth(TreeNode* root) {
//        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
//    }
    
    // add bfs method later, maybe
    
    // not my code, faster
    int num;
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        num = INT_MIN;
        travel(root, 1);
        return num;
    }
    
    void travel(TreeNode* node, int level) {
        if(!node->left && !node->right) {
            num = max(num, level);
            return;
        }
        
        if(node->left) {
            travel(node->left, level+1);
        }
        
        if(node->right) {
            travel(node->right, level+1);
        }
    }
};

int main() {
    return 0;
}
