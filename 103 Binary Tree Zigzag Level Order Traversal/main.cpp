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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vv;
        
        if (root == NULL) {
            return vv;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int levelLength = q.size();
            vector<int> v;
            for (int i = 0; i < levelLength; i++) {
                TreeNode *t = q.front();
                v.push_back(t->val);
                if (t->left != NULL) q.push(t->left);
                if (t->right != NULL) q.push(t->right);
                q.pop();
            }
            if (level % 2 == 1) {
                vv.push_back(v);
            } else {
                reverse(v.begin(), v.end());
                vv.push_back(v);
            }
            level++;
        }
        
        return vv;
    }
};

int main() {
    
    return 0;
}
