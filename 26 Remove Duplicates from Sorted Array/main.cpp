#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // mimic code in stl: algorithm - unique
    int removeDuplicates(vector<int>& nums) {
        if (nums.begin() == nums.end()) {
            return 0;
        }
        
        int result = 0;
        vector<int>::iterator first = nums.begin();
        while (++first != nums.end()) {
            if (*first != nums[result]) {
                nums[++result] = *first;
            }
        }
        
        return ++result;
    }
};

#define COUNT 3
int main() {
    int a[COUNT] = {1,1,2};
    vector<int> nums(a,&a[COUNT]);
    
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
