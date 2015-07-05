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
        store states of each row in the first of that row, and store states of each column in the first of that column. 
        Because the state of row0 and the state of column0 would occupy the same cell, I let it be the state of row0, and use another variable "col0" for column0. 
        In the first phase, use matrix elements to set states in a top-down way. 
        In the second phase, use states to set matrix elements in a bottom-up way.
     */
//    void setZeroes(vector<vector<int> > &matrix) {
//        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
//        
//        for (int i = 0; i < rows; i++) {
//            if (matrix[i][0] == 0) col0 = 0;
//            for (int j = 1; j < cols; j++)
//                if (matrix[i][j] == 0)
//                    matrix[i][0] = matrix[0][j] = 0;
//        }
//        
//        for (int i = rows - 1; i >= 0; i--) {
//            for (int j = cols - 1; j >= 1; j--)
//                if (matrix[i][0] == 0 || matrix[0][j] == 0)
//                    matrix[i][j] = 0;
//            if (col0 == 0) matrix[i][0] = 0;
//        }
//    }
    
    // space O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        vector<int> rowZero;
        vector<int> columnZero;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rowZero.push_back(i);
                    break;
                }
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][i] == 0) {
                    columnZero.push_back(i);
                    break;
                }
            }
        }
        
        for (int i = 0; i < rowZero.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[rowZero[i]][j] = 0;
            }
        }
        for (int i = 0; i < columnZero.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][columnZero[i]] = 0;
            }
        }
    }
};

int main() {
    vector<int> v = {1,0};
    vector<vector<int>> vv = {v};
    Solution s;
    s.setZeroes(vv);
    return 0;
}

