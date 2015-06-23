#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> vv;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> v;
        vv.push_back(v);
        dfs(nums, v, 0);
        return vv;
    }
    
    void dfs(vector<int> &nums, vector<int> v, int start) {
        if (start == nums.size()) {
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            v.push_back(nums[i]);
            vv.push_back(v);
            dfs(nums, v, i+1);
            v.pop_back();
            while (i < nums.size()-1 && nums[i] == nums[i+1]) {
                i++;
            }
        }
    }
};

int main() {
    return 0;
}
