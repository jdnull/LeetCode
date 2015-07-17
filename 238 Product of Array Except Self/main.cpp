#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N,1);
        
        for(int i=0; i<N; i++){
            if (i==0)   res[i] = 1;
            else res[i] = res[i-1]*nums[i-1];
        }
        
        int r_prod = 1;
        for(int i=N-1; i>=0; i--){
            res[i] *= r_prod;
            r_prod *= nums[i];
        }
        
        return res;
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution ss;
    cout << ss.minWindow(s, t) << endl;
}