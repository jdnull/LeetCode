/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <stack>
#include <set>
 
class Solution {
public:
    // not my code, simpler
    // vector<int> preorderTraversal(TreeNode *root) {
    //     vector<int> preOrder;
    //     if(root == NULL) return preOrder;
     
    //     vector<TreeNode *> nodes;
    //     nodes.push_back(root);
        
    //     while(!nodes.empty()) {
    //         Treenode *n = nodes.back();
    //         preOrder.push_back(n->val);
    //         nodes.pop_back();
            
    //         if(n->right) nodes.push_back(n->right);
    //         if(n->left) nodes.push_back(n->left);
    //     }
        
    //     return preOrder;
    // }
    
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preOrder;
        if(root == NULL) return preOrder;
        
        TreeNode *top;
        set<TreeNode *> visited;
        stack<TreeNode *> st;
        
        preOrder.push_back(root->val);
        visited.insert(root);
        st.push(root);
        while(!st.empty()) {
            top = st.top();
            if(top->left != NULL && visited.find(top->left) == visited.end()) {
                preOrder.push_back(top->left->val);
                visited.insert(top->left);
                st.push(top->left);
                continue;
            }
            if(top->right != NULL && visited.find(top->right) == visited.end()) {
                preOrder.push_back(top->right->val);
                visited.insert(top->right);
                st.push(top->right);
                continue;
            }
            st.pop();
        }
        return preOrder;
    }
};