#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        
        int last2 = nums[0];
        int last1 = nums[1];
        
        int p = 1;
        int result = 2;
        
        while (++p < nums.size()) {
            int dupCount = last2 == last1 ? 2 : 1;
            if (nums[p] == last1) {
                dupCount++;
            }
            if (dupCount <= 2) {
                nums[result] = nums[p];
                result++;
                last2 = last1;
                last1 = nums[p];
                
            }
        }
        
        return result;
    }
};

#define COUNT 1
int main() {
    int a[COUNT] = {1};
    vector<int> nums(a, &a[COUNT]);
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    
    return 0;
}
