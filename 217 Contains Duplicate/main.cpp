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
//    bool containsDuplicate(Vector<int>& nums) {
//        return nums.size() > set<int>(nums.begin(), nums.end()).size();
//    }
    
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                return true;
            }
            m.insert(pair<int, int>(nums[i], 0));
        }
        return false;
    }
};

int main() {
    
    return 0;
}