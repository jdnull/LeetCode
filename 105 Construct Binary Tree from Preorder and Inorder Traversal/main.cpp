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
    // improvement: using a hash map to speed up in searching in inorder
    int rootPreIndex = 0;
    
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        rootPreIndex = 0;
        return getRootNode(rootPreIndex, 0, inorder.size()-1, inorder, preorder);
    }
    
    TreeNode* getRootNode(int& rootPreIndex, int childStart, int childEnd, vector<int> &inorder, vector<int> &preorder) {
        if (rootPreIndex < 0 || rootPreIndex >= preorder.size() || childStart > childEnd) {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preorder[rootPreIndex]);
        
        if (childStart == childEnd) {
            rootPreIndex++;
            return root;
        }
        
        int childInIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[rootPreIndex]) {
                childInIndex = i;
                break;
            }
        }
        
        rootPreIndex++;
        root->left = getRootNode(rootPreIndex, childStart, childInIndex-1, inorder, preorder);
        root->right = getRootNode(rootPreIndex, childInIndex+1, childEnd, inorder, preorder);
        return root;
    }
};

int main() {
    int a[3] = {1,2,3};
    vector<int> inorder(a, a + sizeof(a) / sizeof(int));
    int b[3] = {3,2,1};
    vector<int> postorder(b, b + sizeof(b) / sizeof(int));
    Solution s;
    TreeNode *t = s.buildTree(inorder, postorder);
    return 0;
}
