#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
// O(n) method accepted surprisingly
//    int findMin(vector<int>& nums) {
//        int min = nums[0];
//        for(int i = 1; i < nums.size(); i++) {
//            if(min > nums[i]) {
//                min = nums[i];
//            }
//        }
//        return min;
//    }
    
// try O(logn) method
//    Case 1. The leftmost value is less than the rightmost value in the list: This means that the list is not rotated. e.g> [1 2 3 4 5 6 7 ]
//    
//    Case 2. The value in the middle of the list is greater than the leftmost and rightmost values in the list. e.g> [ 4 5 6 7 0 1 2 3 ]
//    
//    Case 3. The value in the middle of the list is less than the leftmost and rightmost values in the list. e.g> [ 5 6 7 0 1 2 3 4 ]
//    
//    As you see in the examples above, if we have case 1, we just return the leftmost value in the list. If we have case 2, we just move to the right side of the list. If we have case 3 we need to move to the left side of the list.
    int findMin(vector<int>& nums) {
        int left = 0,  right = nums.size() - 1;
        while(left < right) {
            if(nums[left] < nums[right])
                return nums[left];
            
            int mid = (left + right)/2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }
};

#define COUNT 8
int main() {
    int num1[COUNT] = {4,5,6,7,0,1,2,3};
    vector<int> v(num1, &num1[COUNT]);
    
    Solution s;
    cout << s.findMin(v) << endl;
    
    return 0;
}
