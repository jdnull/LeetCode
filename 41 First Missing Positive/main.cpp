#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++ i)
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for(int i = 0; i < nums.size(); ++ i)
            if(nums[i] != i + 1)
                return i + 1;
        
        return nums.size() + 1;
    }
};

#define COUNT 4
int main() {
    int a[COUNT] = {3,4,-1,1};
    vector<int> candidates(a, &a[COUNT]);
    Solution s;
    cout << s.firstMissingPositive(candidates) << endl;
}
