#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // terrible time consuming
//    int minSubArrayLen(int s, vector<int>& nums) {
//        int windowLen = nums.size()+1;
//        
//        for (int i = 0; i < nums.size(); i++) {
//            int start = i;
//            int end = i+1;
//            int sum = nums[start];
//            while (sum < s && end < nums.size()) {
//                sum += nums[end];
//                end++;
//            }
//            if (sum >= s && end - start < windowLen) {
//                windowLen = end-start;
//            }
//        }
//        
//        return windowLen == nums.size()+1 ? 0 : windowLen;
//    }
    
    // not my code
    // while loops at most N times during looping for-loop from 1 to N. So, N + N = O(N).
    int minSubArrayLen(int s, vector<int>& nums) {
        int firstPos = 0, sum = 0, minLength = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                minLength = min(minLength, i - firstPos + 1);
                sum -= nums[firstPos++];
            }
        }
        
        return minLength == INT_MAX? 0 : minLength;
    }
};

int main() {
    
    return 0;
}