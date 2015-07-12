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
//    bool containsNearbyDuplicate(vector<int>& nums, int k)
//    {
//        unordered_set<int> s;
//        
//        if (k <= 0) return false;
//        if (k >= nums.size()) k = nums.size() - 1;
//        
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i > k) s.erase(nums[i - k - 1]);
//            if (s.find(nums[i]) != s.end()) return true;
//            s.insert(nums[i]);
//        }
//        
//        return false;
//    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                } else {
                    m[nums[i]] = i;
                }
            } else {
                m.insert(pair<int, int>(nums[i], i));
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}