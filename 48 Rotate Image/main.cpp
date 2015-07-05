#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code
    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry 
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    // void rotate(vector<vector<int> > &matrix) {
    //     reverse(matrix.begin(), matrix.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }
    
    /*
     * anticlockwise rotate
     * first reverse left to right, then swap the symmetry
     * 1 2 3     3 2 1     3 6 9
     * 4 5 6  => 6 5 4  => 2 5 8
     * 7 8 9     9 8 7     1 4 7
    */
    // void anti_rotate(vector<vector<int> > &matrix) {
    //     for (auto vi : matrix) reverse(vi.begin(), vi.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }
    
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
