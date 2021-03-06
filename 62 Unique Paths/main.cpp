#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    // optimize space complexity from O(n*n) to O(n);
    int uniquePaths(int m, int n) {
        vector<int> v;
        v.resize(n);
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    v[j] = 1;
                } else if (i == m-1) {
                    v[j] = v[j+1];
                } else if(j == n-1) {
                    ;
                } else {
                    v[j] = v[j] + v[j+1];
                }
            }
        }
        
        return v[0];
    }
    
    // space somplexity O(n*n)
    // int uniquePaths(int m, int n) {
    //     vector<vector<int> > vv;
    //     for (int i = 0; i < m; i++) {
    //         vector<int> v;
    //         v.resize(n);
    //         vv.push_back(v);
    //     }
        
    //     for (int i = m-1; i >= 0; i--) {
    //         for (int j = n-1; j >= 0; j--) {
    //             if (i == m-1 && j == n-1) {
    //                 vv[i][j] = 1;
    //             } else if (i == m-1) {
    //                 vv[i][j] = vv[i][j+1];
    //             } else if(j == n-1) {
    //                 vv[i][j] = vv[i+1][j];
    //             } else {
    //                 vv[i][j] = vv[i+1][j] + vv[i][j+1];
    //             }
    //         }
    //     }
        
    //     return vv[0][0];
    // }
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    
    return 0;
}
