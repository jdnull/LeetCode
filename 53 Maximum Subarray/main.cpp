#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    // not my code, divide and conquer
    /*
         Step1. Select the middle element of the array. So the maximum subarray may contain that middle element or not.
         
         Step 2.1 If the maximum subarray does not contain the middle element, then we can apply the same algorithm to the the subarray to the left of the middle element and the subarray to the right of the middle element.
         
         Step 2.2 If the maximum subarray does contain the middle element, then the result will be simply the maximum suffix subarray of the left subarray plus the maximum prefix subarray of the right subarray
         
         Step 3 return the maximum of those three answer.
     */
//    int maxSubArray(int A[], int n) {
//        // IMPORTANT: Please reset any member data you declared, as
//        // the same Solution instance will be reused for each test case.
//        if(n==0) return 0;
//        return maxSubArrayHelperFunction(A,0,n-1);
//    }
//    
//    int maxSubArrayHelperFunction(int A[], int left, int right) {
//        if(right == left) return A[left];
//        int middle = (left+right)/2;
//        int leftans = maxSubArrayHelperFunction(A, left, middle);
//        int rightans = maxSubArrayHelperFunction(A, middle+1, right);
//        int leftmax = A[middle];
//        int rightmax = A[middle+1];
//        int temp = 0;
//        for(int i=middle;i>=left;i--) {
//            temp += A[i];
//            if(temp > leftmax) leftmax = temp;
//        }
//        temp = 0;
//        for(int i=middle+1;i<=right;i++) {
//            temp += A[i];
//            if(temp > rightmax) rightmax = temp;
//        }
//        return max(max(leftans, rightans),leftmax+rightmax);
//    }
    
    // not my code,
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], i, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
    
    // not my code, space complexity O(1)
//    int maxSubArray(vector<int>& nums) {
//        if (nums.size() == 0) {
//            return 0;
//        }
//        int curMax = nums[0], preMax = nums[0];
//        for (int i = 1; i < nums.size(); i++){
//            preMax = max(preMax+nums[i], nums[i]);
//            curMax = max(curMax, preMax);
//        }
//        return curMax;
//    }
    
//    int maxSubArray(vector<int>& nums) {
//        if (nums.size() == 0) {
//            return 0;
//        }
//        
//        vector<int> v;
//        v.resize(nums.size(), 0);
//        v[0] = nums[0];
//        int ret = v[0];
//        for (int i = 1; i < nums.size(); i++) {
//            v[i] = max(nums[i] + v[i-1], nums[i]);
//            ret = max(v[i], ret);
//        }
//        return ret;
//    }
};

int main() {
    
    return 0;
}
