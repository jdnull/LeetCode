#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        if (nums.size() == 0) {
            return ret;
        }
        
        int low = 0, high = nums.size()-1;
        int find = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                high = mid-1;
            } else if (nums[mid] < target) {
                low = mid+1;
            }
        }
        
        if (low < nums.size() && nums[low] == target) {
            ret[0] = low;
        } else {
            return ret;
        }
        
        high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid-1;
            } else if (nums[mid] <= target) {
                low = mid+1;
            }
        }
        ret[1] = high;
        return ret;
    }
};

#define COUNT 6
int main() {
    int a[COUNT] = {5, 7, 7, 8, 8, 10};
    vector<int> v(a, &a[COUNT]);

    Solution s;
    vector<int> ret = s.searchRange(v, 8);
    cout << ret[0] << ret[1] << endl;
    return 0;
}
