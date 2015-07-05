#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        if (n < 0) {
            return;
        }
        
        for (int i = 0, j = 0; i < n/2+1; i++, j++) {
            for (int k = j; k < n-j; k++) {
                int t = matrix[i][k];
                matrix[i][k] = matrix[n-k][i];
                matrix[n-k][i] = matrix[n-i][n-k];
                matrix[n-i][n-k] = matrix[k][n-i];
                matrix[k][n-i] = t;
            }
        }
    }
};

int main() {
    return 0;
}

struct BT {
    BT* left;
    BT* right;
    int val;
    BT(int val) : val(val) {}
};
