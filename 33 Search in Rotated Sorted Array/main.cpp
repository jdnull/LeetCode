#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code
    // int search(int[] A, int target) {
    //     int lo = 0;
    //     int hi = A.length - 1;
    //     while (lo < hi) {
    //         int mid = (lo + hi) / 2;
    //         if (A[mid] == target) return mid;
    
    //         if (A[lo] <= A[mid]) {
    //             if (target >= A[lo] && target < A[mid]) {
    //                 hi = mid - 1;
    //             } else {
    //                 lo = mid + 1;
    //             }
    //         } else {
    //             if (target > A[mid] && target <= A[hi]) {
    //                 lo = mid + 1;
    //             } else {
    //                 hi = mid - 1;
    //             }
    //         }
    //     }
    //     return A[lo] == target ? lo : -1;
    // }

    // not my code
    // int search(int A[], int n, int target) {
    //     int lo=0,hi=n-1;
    //     // find the index of the smallest value using binary search.
    //     // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    //     // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    //     while(lo<hi){
    //         int mid=(lo+hi)/2;
    //         if(A[mid]>A[hi]) lo=mid+1;
    //         else hi=mid;
    //     }
    //     // lo==hi is the index of the smallest value and also the number of places rotated.
    //     int rot=lo;
    //     lo=0;hi=n-1;
    //     // The usual binary search and accounting for rotation.
    //     while(lo<=hi){
    //         int mid=(lo+hi)/2;
    //         int realmid=(mid+rot)%n;
    //         if(A[realmid]==target)return realmid;
    //         if(A[realmid]<target)lo=mid+1;
    //         else hi=mid-1;
    //     }
    //     return -1;
    // }
    
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
