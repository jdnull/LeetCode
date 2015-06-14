#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // not my code, BFS
//    bool isSymmetric(TreeNode *root) {
//        // Level-order BFS.
//        queue<nodepair> q;
//        if(root)
//            q.push(make_pair(root->left,root->right));
//        while(q.size()){
//            nodepair p=q.front(); q.pop();
//            if(p.first){
//                if(!p.second)return false;
//                if(p.first->val != p.second->val) return false;
//                // the order of children pushed to q is the key to the solution.
//                q.push(make_pair(p.first->left,p.second->right));
//                q.push(make_pair(p.first->right,p.second->left));
//            }
//            else if(p.second) return false;
//        }
//        return true;
//    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL) {
            return false;
        }
        
        return (left->val == right->val) && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

int main() {
    
    return 0;
}
