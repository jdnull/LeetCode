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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > vv;
        if (root == NULL) {
            return vv;
        }
        vector<int> v;
        findPath(vv, v, root, sum);
        return vv;
    }
    
    void findPath(vector<vector<int> > &vv, vector<int> v, TreeNode* root, int sum) {
        v.push_back(root->val);
        
        if (root->val == sum && root->left == NULL && root->right == NULL) {
            vv.push_back(v);
            return;
        } else {
            if (root->left) {
                findPath(vv, v, root->left, sum-root->val);
            }
            if (root->right) {
                findPath(vv, v, root->right, sum-root->val);
            }
        }
    }
};

int main() {
    
    
    return 0;
}
