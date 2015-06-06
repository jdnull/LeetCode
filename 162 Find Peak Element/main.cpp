#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // O(n), accept....
//    int findPeakElement(vector<int>& nums) {
//        int maxIndex = 0;
//        for(int i = 1; i < nums.size(); i++) {
//            if(nums[maxIndex] < nums[i]) {
//                maxIndex = i;
//            }
//        }
//        return maxIndex;
//    }
    
    // another O(n), not my code
//    int findPeakElement(const vector<int> &num) {
//        for(int i = 1; i < num.size(); i ++)
//        {
//            if(num[i] < num[i-1])
//            {// <
//                return i-1;
//            }
//        }
//        return num.size()-1;
//    }
    
    // recursion
//    int findPeakElement(const vector<int> &num) {
//        return Helper(num, 0, num.size()-1);
//    }
//    int Helper(const vector<int> &num, int low, int high)
//    {
//        if(low == high)
//            return low;
//        else
//        {
//            int mid1 = (low+high)/2;
//            int mid2 = mid1+1;
//            if(num[mid1] > num[mid2])
//                return Helper(num, low, mid1);
//            else
//                return Helper(num, mid2, high);
//        }
//    }
    
    // binary search
    int findPeakElement(const vector<int> &num)
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};

#define COUNT 4
int main() {
    int a[COUNT] = {1,2,3,1};
    vector<int> v(a, &a[COUNT]);

    Solution s;
    cout << s.findPeakElement(v) << endl;
    return 0;
}
