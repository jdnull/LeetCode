#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // not my code, refer to 84
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        vector<vector<int> > height(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    height[i][j] = (i == 0) ? 1 : height[i-1][j] + 1;
                }
            }
        }
        
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
            maxArea = max(maxArea, largestRectangleArea(height[i]));
        }
        return  maxArea;
    }
    
    int largestRectangleArea(vector<int>& height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        
        for(int i = 0; i < height.size(); i++)
        {
            while(index.size() > 0 && height[index.back()] >= height[i])
            {
                int h = height[index.back()];
                index.pop_back();
                
                int sidx = index.size() > 0 ? index.back() : -1;
                if(h * (i-sidx-1) > ret)
                    ret = h * (i-sidx-1);
            }
            index.push_back(i);
        }
        
        return ret;
    }
};

#define COUNT 6
int main() {
    
    return 0;
}
