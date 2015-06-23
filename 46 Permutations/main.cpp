#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    
    // not my code, space complexity O(n), faster
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        permuteRecursive(num, 0, result);
        return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
        
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
    
    // not my code, set visited flags
//    vector<vector<int>> vv;
//    
//    vector<vector<int>> permute(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<int> v;
//        vector<bool> isVisited(nums.size(), false);
//        dfs(nums, v, isVisited);
//        return vv;
//    }
//    
//    void dfs(vector<int> &nums, vector<int> v, vector<bool> isVisited) {
//        if (v.size() == nums.size()) {
//            vv.push_back(v);
//            return;
//        }
//        
//        for (int i = 0; i < nums.size(); i++) {
//            if (!isVisited[i]) {
//                isVisited[i] = true;
//                v.push_back(nums[i]);
//                dfs(nums, v, isVisited);
//                v.pop_back();
//                isVisited[i] = false;
//            }
//        }
//    }
    
    // my code
//    vector<vector<int>> vv;
//    
//    vector<vector<int>> permute(vector<int>& nums) {
//        sort(nums.begin(), nums.end()); // no need to sort
//        vector<int> v;
//        dfs(nums, v);
//        return vv;
//    }
//    
//    void dfs(vector<int> nums, vector<int> v) {
//        if(nums.size() == 0) {
//            vv.push_back(v);
//            return;
//        }
//        for(int i = 0; i < nums.size(); i++) {
//            v.push_back(nums[i]);
//            vector<int> tempNums;
//            for(int j = 0; j < nums.size(); j++) {
//                if(j != i) {
//                    tempNums.push_back(nums[j]);
//                }
//            }
//            dfs(tempNums, v);
//            v.pop_back();
//        }
//    }
};

int main() {
    return 0;
}
