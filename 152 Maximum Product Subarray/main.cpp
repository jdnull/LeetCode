#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    // not my code
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        
        int ret = nums[0];
        int minP = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxP;
            maxP = max(max(temp * nums[i], nums[i]), minP * nums[i]);
            minP = min(min(temp * nums[i], nums[i]), minP * nums[i]);
            ret = max(ret, maxP);
        }
        
        return ret;
    }
};

int main() {
    
    return 0;
}
