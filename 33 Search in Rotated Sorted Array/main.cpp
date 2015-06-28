#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        return search(nums, target, 0, nums.size()-1);
    }
    
    int search(vector<int>& nums, int target, int start, int end) {
        if (start >= end) {
            return nums[start] == target ? start : -1;
        }
        if (nums[start] <= nums[end]) {
            return binarySearch(nums, target, start, end);
        } else {
            if (target > nums[nums.size()-1] && target < nums[start]) {
                return -1;
            } else {
                int mid = (start + end) / 2;
                if (nums[start] > nums[mid]) {
                    if (nums[mid] <= target && target <= nums[end]) {
                        return binarySearch(nums, target, mid, end);
                    } else {
                        return search(nums, target, start, mid-1);
                    }
                } else {
                    if (nums[start] <= target && target <= nums[mid]) {
                        return binarySearch(nums, target, start, mid);
                    } else {
                        return search(nums, target, mid+1, end);
                    }
                }
            }
        }
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        if (start >= end) {
            return nums[start] == target ? start : -1;
        }
        
        int mid = (start + end) / 2;
        if (nums[mid] > target) {
            return binarySearch(nums, target, start, mid-1);
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid+1, end);
        } else {
            return mid;
        }
    }
};

int main() {
    return 0;
}
