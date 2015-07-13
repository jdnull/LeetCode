#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code
    // At the max there can only be 2 possible candidates.
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums;
        
        int box1 = INT_MIN, box2 = INT_MIN, count1(0),count2(0);
        for(int i =0;i<n;i++){
            if(nums[i] == box1) count1++;
            else if(nums[i] == box2) count2++;
            else if(count1==0){
                box1 = nums[i];
                count1=1;
            }
            else if(count2==0){
                box2 = nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        //At the end of the loop box1 and box2 will be holding the possible candidates. Now clear counters and run loop again, to check if the candidates occurence is more than n/3
        count1=0;
        count2=0;
        for(int i =0;i<n;i++){
            if(nums[i] == box1) count1++;
            else if(nums[i]==box2) count2++;
        }
        vector<int> ans;
        if(count1 > n/3) ans.push_back(box1);
        if(count2 > n/3) ans.push_back(box2);
        return ans;
    }
};

int main() {
    
    return 0;
}