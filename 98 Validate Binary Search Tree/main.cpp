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
    // not my code, but safer
//    bool isValidBST(TreeNode* root) {
//        TreeNode* prev = NULL;
//        return validate(root, NULL);
//    }
//    bool validate(TreeNode* node, TreeNode* &prev) {
//        if (node == NULL) return true;
//        if (!validate(node->left, prev)) return false;
//        if (prev != NULL && prev->val >= node->val) return false;
//        prev = node;
//        return validate(node->right, prev);
//    }
    
    // not my code, faster
//    bool isValidBST(TreeNode *root) {
//        return valid(root, LLONG_MIN, LLONG_MAX);
//    }
//    
//    bool valid(TreeNode *node, long long min, long long max) {
//        if (node == NULL) {
//            return true;
//        }
//        
//        if (node->val <= min || node->val >= max) {
//            return false;
//        }
//        
//        return valid(node->left, min, node->val) && valid(node->right, node->val, max);
//        
//    }
    
    // my code, time complexity o(n^2)
    bool isValidBST(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return true;
        }
        
        int leftMax = findMaxNode(root->left);
        int rightMin = findMinNode(root->right);
        
        if (root->left && root->right == NULL) {
            if (leftMax < root->val) {
                return isValidBST(root->left);
            } else {
                return false;
            }
        } else if (root->left == NULL && root->right) {
            if (root->val < rightMin) {
                return isValidBST(root->right);
            } else {
                return false;
            }
        } else {
            if (leftMax < root->val && root->val < rightMin) {
                return isValidBST(root->left) && isValidBST(root->right);
            } else {
                return false;
            }
        }
    }
    
    int findMaxNode(TreeNode *root) {
        if (root == NULL) {
            return INT_MIN;
        }
        int leftMax = findMaxNode(root->left);
        int rightMax = findMaxNode(root->right);
        return max(root->val, max(leftMax, rightMax));
    }
    
    int findMinNode(TreeNode *root) {
        if (root == NULL) {
            return INT_MAX;
        }
        int leftMin = findMinNode(root->left);
        int rightMin = findMinNode(root->right);
        return min(root->val, min(leftMin, rightMin));
    }
};

int main() {
    
    
    return 0;
}
