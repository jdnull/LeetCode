#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> v(n);
        vector<vector<int>> vv(n, v);
        
        int x0 = 0, x1 = n-1; // Vertical
        int y0 = 0, y1 = n-1; // Horizontal
        int count = 1;
        while (x0 <= x1 || y0 <= y1) {
            // rightward
            for (int i = y0; i <= y1; i++) {
                vv[x0][i] = count;
                count++;
            }
            x0++;
            
            // downward
            for (int i = x0; i <= x1; i++) {
                vv[i][y1] = count;
                count++;
            }
            y1--;
            
            if (x0 > x1) break;
            // leftward
            for (int i = y1; i >= y0; i--) {
                vv[x1][i] = count;
                count++;
            }
            x1--;
            
            if (y0 > y1) break;
            for (int i = x1; i >= x0; i--) {
                vv[i][y0] = count;
                count++;
            }
            y0++;
        }
        
        return vv;
    }
};

int main() {
    
    return 0;
}

