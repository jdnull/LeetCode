#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return ans;
        
        int m = matrix.size(), n = matrix[0].size();
        int x0 = 0, x1 = m - 1; // vertical
        int y0 = 0, y1 = n - 1; // horizon
        
        while(x0 <= x1 && y0 <= y1) {
            // travel right side
            for (int j = y0; j <= y1; ++j)
                ans.push_back(matrix[x0][j]);
            x0++;
            
            // travel down side
            for (int i = x0; i <= x1; ++i)
                ans.push_back(matrix[i][y1]);
            y1--;
            
            if (x0 > x1) break;
            // travel left side
            for (int j = y1; j >= y0; --j)
                ans.push_back(matrix[x1][j]);
            x1--;
            
            if (y0 > y1) break;
            // travel up side
            for (int i = x1; i >= x0; --i)
                ans.push_back(matrix[i][y0]);
            y0++;
        }
        
        return ans;
    }
};

int main() {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};
    vector<int> v3 = {7,8,9};
    vector<vector<int>> vv = {v1,v2,v3};
    
    Solution s;
    vector<int> v = s.spiralOrder(vv);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}

