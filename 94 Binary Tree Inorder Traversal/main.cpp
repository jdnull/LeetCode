#include <iostream>
#include <algorithm>
#include <vector>
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
    // not my code, less space consuming
//    vector<int> inorderTraversal(TreeNode *root) {
//        vector<int> inOrder;
//        if (root == NULL) {
//            return inOrder;
//        }
//        
//        vector<TreeNode *> nodes;
//        TreeNode *n = root;
//        while (n || !nodes.empty()) {
//            while (n) {
//                nodes.push_back(n);
//                n = n->left;
//            }
//            
//            if (!nodes.empty()) {
//                n = nodes.back();
//                inOrder.push_back(n->val);
//                
//                nodes.pop_back();
//                n = n->right;
//            }
//        }
//        
//        return inOrder;
//    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        if (root == NULL) {
            return inOrder;
        }
        
        map<TreeNode *, bool> visited;
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            TreeNode *n = nodes.back();
            if (n->left && !visited[n->left]) {
                nodes.push_back(n->left);
                continue;
            }
            nodes.pop_back();
            visited[n] = true;
            inOrder.push_back(n->val);
            if (n->right) {
                nodes.push_back(n->right);
            }
        }
        
        return inOrder;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    
    Solution s;
    vector<int> v = s.inorderTraversal(root);
    
    return 0;
}
