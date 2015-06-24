#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // not my code, simpler
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        
        int jump = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            jump--;
            if (jump < 0) {
                return false;
            }
            if (jump < nums[i]) {
                jump = nums[i];
            }
        }
        return true;
    }
    
    // faster, not code is not simple
//    bool canJump(vector<int>& nums) {
//        if (nums.size() == 0) {
//            return true;
//        }
//        
//        return dfs(nums, 0);
//    }
//    
//    bool dfs(vector<int>& nums, int start) {
//        if (start == nums.size()-1) {
//            return true; // reach the last index
//        }
//        
//        if (nums[start] == 0) {
//            return false; // reach a zero number, and not the last index
//        }
//        
//        int maxIndex = start;
//        for (int i = start+1; i <= start+nums[start]; i++) {
//            if (i == nums.size()-1) {
//                return true; // reach the last index
//            }
//            if (maxIndex+nums[maxIndex] <= i+nums[i]) {
//                maxIndex = i; // get the index as far as possible
//            }
//        }
//        return dfs(nums, maxIndex);
//    }
    
    // Time limits
//    bool canJump(vector<int>& nums) {
//        if (nums.size() == 0) {
//            return true;
//        }
//        vector<int> flags;
//        flags.resize(nums.size(), false);
//        flags[nums.size()-1] = true;
//        
//        for (int i = nums.size()-2; i >= 0; i--) {
//            for (int j = i+nums[i]; j > i; j--) {
//                if (j < nums.size() && flags[j]) {
//                    flags[i] = true;
//                    break;
//                }
//            }
//        }
//        
//        return flags[0];
//    }
};

int main() {
    return 0;
}
