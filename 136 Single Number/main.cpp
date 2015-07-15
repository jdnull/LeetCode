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
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};

int main() {
    vector<int> v = {1,1,2,3,2,4,4};
    Solution s;
    cout << s.singleNumber(v) << endl;
}