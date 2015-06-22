#include <iostream>
#include <algorithm>
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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
    
    vector<TreeNode *> dfs(int start, int stop) {
        vector<TreeNode *> v;
        if (start > stop) {
            v.push_back(NULL);
            return v;
        }
        
        for (int i = start; i <= stop; i++) {
            vector<TreeNode *> l = dfs(start, i-1);
            vector<TreeNode *> r = dfs(i+1, stop);
            
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = l[j];
                    node->right = r[k];
                    v.push_back(node);
                }
            }
        }
        
        return v;
    }
};

int main() {
    return 0;
}
