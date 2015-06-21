#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        
        vector<vector<int> > vv;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            vector<int> v;
            v.resize(obstacleGrid[0].size());
            vv.push_back(v);
        }
        
        for (int i = obstacleGrid.size()-1; i >= 0; i--) {
            for (int j = obstacleGrid[0].size()-1; j >= 0; j--) {
                if (i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) {
                    vv[i][j] = obstacleGrid[i][j] == 1 ? 0 : 1;
                } else if (i == obstacleGrid.size()-1) {
                    vv[i][j] = obstacleGrid[i][j] == 1 ? 0 : vv[i][j+1];
                } else if (j == obstacleGrid[0].size()-1) {
                    vv[i][j] = obstacleGrid[i][j] == 1 ? 0 : vv[i+1][j];
                } else {
                    vv[i][j] = obstacleGrid[i][j] == 1 ? 0 : vv[i+1][j] + vv[i][j+1];
                }
            }
        }
        return vv[0][0];
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
    cout << s.uniquePathsWithObstacles(vv) << endl;
    
    return 0;
}
