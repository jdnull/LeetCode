/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <vector>
#include <stack>
#include <set>
 
class Solution {
public:
    // not my code
    // vector<int> postorderTraversal(TreeNode *root) {
    //     vector<int> postOrder;
    //     if(root == NULL) return postOrder;
        
    //     TreeNode *pre = NULL;
    //     vector<TreeNode *> nodes;
    //     nodes.push_back(root);
    //     while(!nodes.empty()) {
    //         TreeNode *n = nodes.back();
    //         if((n->left == NULL && n->right) || (pre != NULL && (pre == n->left || pre == n->right))) {
    //             postOrder.push_back(n->val);
    //             pre = n;
    //             postOrder.pop_back();
    //         } else {
    //             if(n->right) nodes.push_back(n->right);
    //             if(n->left) nodes.push_back(n->left);
    //         }
    //     }
    //     return postOrder;
    // }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> retVector;
        
        if(root == NULL) return retVector;
        
        set<TreeNode *> visitedNodes;
        set<TreeNode *>::iterator it;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *top;
        while(!st.empty()) {
            top = st.top();
            it = visitedNodes.find(top->left);
            if(top->left != NULL && it == visitedNodes.end()) {
                st.push(top->left);
                continue;
            }
            it = visitedNodes.find(top->right);
            if(top->right != NULL && it == visitedNodes.end()) {
                st.push(top->right);
                continue;
            }
            retVector.push_back(top->val);
            st.pop();
            visitedNodes.insert(top);
        }
        return retVector;
    }
};