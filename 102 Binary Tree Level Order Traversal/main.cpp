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
    // bfs, not my code
//    vector<vector<int>> levelOrder(TreeNode *root) {
//        vector<vector<int>> levels;
//        if(!root) return levels;
//        queue<TreeNode*> toVisit;
//        toVisit.push(root);
//        int numLevelNodes = 1;
//        while(!toVisit.empty()) {
//            vector<int> level;
//            for (int i = 0; i < numLevelNodes; i++) {
//                TreeNode* node = toVisit.front();
//                toVisit.pop();
//                level.push_back(node -> val);
//                if(node -> left) toVisit.push(node -> left);
//                if(node -> right) toVisit.push(node -> right);
//            }
//            levels.push_back(level);
//            numLevelNodes = toVisit.size();
//        }
//        return levels;
//    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > vv;
        dfs(vv, root, 1);
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
