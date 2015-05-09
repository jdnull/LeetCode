#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) {
                nums.erase(it);
            } else {
                it++;
            }
        }
        
        return nums.size();
    }
};

#define COUNT 3
int main() {
    int a[COUNT] = {1,1,2};
    vector<int> nums(a,&a[COUNT]);
    
    Solution s;
    cout << s.removeElement(nums,2) << endl;
    return 0;
}
