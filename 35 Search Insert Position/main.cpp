#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    // recursive method, not my code
//    int search(int A[], int start, int end, int target) {
//        if (start > end) return start;
//        int mid = (start + end) / 2;
//        if (A[mid] == target) return mid;
//        else if (A[mid] > target) return search(A, start, mid - 1, target);
//        else return search(A, mid + 1, end, target);
//    }
//    int searchInsert(int A[], int n, int target) {
//        return search(A, 0, n - 1, target);
//    }
    
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            if (nums.size() >= target) {
                return 0;
            } else {
                return 1;
            }
        }
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = -1;
        while (end - start != 1) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                break;
            } else {
                if (nums[mid] > target) {
                    end = mid;
                } else {
                    start = mid;
                }
            }
            if (start == end) {
                mid = start;
            }
        }
        
        if (end - start == 1) {
            if (nums[start] >= target) {
                mid = start;
            } else if (nums[end] >= target){
                mid = end;
            } else {
                mid = end + 1;
            }
        }
        
        return mid;
    }
};

#define COUNT 1
int main() {
    int a[COUNT] = {1};
    vector<int> nums(a, &a[COUNT]);
    Solution s;
    cout << s.searchInsert(nums, 6) << endl;
    return 0;
}
