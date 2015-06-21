#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        
        vector<int> v;
        v.resize(grid[0].size());
        
        for (int i = grid.size()-1; i >= 0; i--) {
            for (int j = grid[0].size()-1; j >= 0; j--) {
                if (i == grid.size()-1 && j == grid[0].size()-1) {
                    v[j] = grid[i][j];
                } else if (i == grid.size()-1) {
                    v[j] = v[j+1] + grid[i][j];
                } else if (j == grid[0].size()-1) {
                    v[j] = v[j] + grid[i][j];
                } else {
                    v[j] = v[j] < v[j+1] ? v[j]+grid[i][j] : v[j+1]+grid[i][j];
                }
            }
        }
        return v[0];
    }
};

#define COUNT 3
int main() {
    vector<vector<int> > vv;
    int a1[COUNT] = {0,0,1};
    vector<int> v1(a1, &a1[COUNT]);
    vv.push_back(v1);
    
    int a2[COUNT] = {0,0,0};
    vector<int> v2(a2, &a2[COUNT]);
    vv.push_back(v2);
    
    int a3[COUNT] = {0,0,0};
    vector<int> v3(a3, &a3[COUNT]);
    vv.push_back(v3);
    
    Solution s;
    cout << s.minPathSum(vv) << endl;
    
    return 0;
}
