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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > vv;
        dfs(vv, root, 1);
        for (int i = 0; i < vv.size() - i; i++) {
            vector<int> tv = vv[i];
            vv[i] = vv[vv.size()-1-i];
            vv[vv.size()-1-i] = tv;
        }
        return vv;
    }
    
    void dfs(vector<vector<int> > &vv, TreeNode *root, int depth) {
        if (root == NULL) {
            return;
        }
        if (vv.size() < depth) {
            vector<int> v;
            vv.push_back(v);
        }
        vv[depth-1].push_back(root->val);
        if (root->left != NULL) {
            dfs(vv, root->left, depth+1);
        }
        if (root->right != NULL) {
            dfs(vv, root->right, depth+1);
        }
    }
};

int main() {
    
    return 0;
}
