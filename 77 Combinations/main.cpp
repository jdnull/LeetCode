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
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > rslt;
        vector<int> path(k, 0);
        combine(n, k, rslt, path);
        return rslt;
    }
    
    void combine(int n, int k, vector<vector<int> > &rslt, vector<int> &path) {
        if (k == 0) {
            rslt.push_back(path);
            return;
        }
        for (int i = n; i >= 1; i--) {
            path[k - 1] = i;
            combine(i - 1, k - 1, rslt, path);
        }
    }
};

int main() {
    return 0;
}
