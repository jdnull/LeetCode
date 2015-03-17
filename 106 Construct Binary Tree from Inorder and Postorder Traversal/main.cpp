#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rootPostIndex = 0;
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        rootPostIndex = postorder.size() - 1;
        return getRootNode(rootPostIndex, 0, inorder.size()-1, inorder, postorder);
    }
    
    TreeNode* getRootNode(int& rootPostIndex, int childStart, int childEnd, vector<int> &inorder, vector<int> &postorder) {
        if (rootPostIndex < 0 || childStart > childEnd) {
            return NULL;
        }
        
        TreeNode *rootNode = new TreeNode(postorder[rootPostIndex]);
        
        if (childStart == childEnd) {
            rootPostIndex--;
            return rootNode;
        }
        
        int childRootInIndex = -1;
        for (int i = childStart; i <= childEnd; i++) {
            if (inorder[i] == postorder[rootPostIndex]) {
                childRootInIndex = i;
                break;
            }
        }
        
        rootPostIndex--;
        rootNode->right = getRootNode(rootPostIndex, childRootInIndex+1, childEnd, inorder, postorder);
        rootNode->left = getRootNode(rootPostIndex, childStart, childRootInIndex-1, inorder, postorder);
        
        return rootNode;
    }
};

int main() {
    int a[4] = {1,2,3,4};
    vector<int> inorder(a, a + sizeof(a) / sizeof(int));
    int b[4] = {1,4,3,2};
    vector<int> postorder(b, b + sizeof(b) / sizeof(int));
    Solution s;
    TreeNode *t = s.buildTree(inorder, postorder);
    return 0;
}
