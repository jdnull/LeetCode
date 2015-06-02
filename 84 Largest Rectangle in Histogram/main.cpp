#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // not my code
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
    int num1[COUNT] = {2,1,5,6,2,3};
    vector<int> v(num1, &num1[COUNT]);
    
    Solution s;
    cout << s.largestRectangleArea(v) << endl;
    
    return 0;
}
