#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if (nums.empty()) {
            return v;
        }
        int start = 0, end = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i+1] == nums[end]+1) {
                end++;
                continue;
            }
            string s = start == end ? intToString(nums[i]) : intToString(nums[start]) + "->" + intToString(nums[end]);
            v.push_back(s);
            start = i+1, end = i+1;
        }

        v.push_back(start == end ? intToString(nums[start]) : intToString(nums[start]) + "->" + intToString(nums[end]));
        
        return v;
    }
    
    string intToString(int i) {
        stringstream ss;
        ss << i;
        return ss.str();
    }
};

int main() {
    vector<int> v = {0,3};
    
    Solution s;
    vector<string> vs = s.summaryRanges(v);
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i] << endl;
    }
    return 0;
}