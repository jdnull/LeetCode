#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /*
         when there could be duplicates in the array, the worst case is O(n).
         
         To explain why, consider this sorted array 1111115, which is rotated to 1151111.
         
         Assume left = 0 and mid = 3, and the target we want to search for is 5. 
         Therefore, the condition A[left] == A[mid] holds true, which leaves us with only two possibilities:
         
         All numbers between A[left] and A[right] are all 1's.
         Different numbers (including our target) may exist between A[left] and A[right].
         As we cannot determine which of the above is true, the best we can do is to move left one step to the right and repeat the process again. 
         Therefore, we are able to construct a worst case input which runs in O(n), for example: the input 11111111...115.
     */
    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
    
    bool search(vector<int> &nums, int target, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) { // for such case: 1151111
                int i = mid-1, j = mid+1;
                while (nums[mid] == nums[i] && i > 0) {
                    i--;
                }
                while (nums[mid] == nums[j] && j < nums.size()-1) {
                    j++;
                }
                return search(nums, target, start, i) || search(nums, target, j, end);
            } else if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    int i = mid-1;
                    while (nums[i] == nums[mid] && i > 0) {
                        i--;
                    }
                    end = i;
                } else {
                    int i = mid+1;
                    while (nums[i] == nums[mid] && i < nums.size()-1) {
                        i++;
                    }
                    start = i;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    int i = mid+1;
                    while (nums[i] == nums[mid] && i < nums.size()-1) {
                        i++;
                    }
                    start = i;
                } else {
                    int i = mid-1;
                    while (nums[i] == nums[mid] && i > 0) {
                        i--;
                    }
                    end = i;
                }
            }
        }
        return nums[start] == target ? true : false;
    }
};

int main() {
    
    return 0;
}

