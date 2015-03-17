#include <iostream>
#include <string>
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) {
            return NULL;
        }
        return getRootNode(num, 0, num.size()-1);
    }
    
    TreeNode *getRootNode(vector<int> &num, int begin, int end) {
        if ((end-begin) == 0) {
            return new TreeNode(num[begin]);
        }

        int mid = (end + begin) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        if (mid-1 >= begin) {
            root->left = getRootNode(num, begin, mid-1);
        }
        if (mid+1 <= end) {
            root->right = getRootNode(num, mid+1, end);
        }
        
        return root;
    }
};

int main() {
    return 0;
}
