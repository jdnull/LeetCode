#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // not my code, faster
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        if (i == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < num.size(); k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, res);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
    
    // my code, too slow
//    vector<vector<int>> vv;
//    
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
//                while(i < nums.size()-1 && nums[i] == nums[i+1]) {
//                    i++;
//                }
//            }
//        }
//    }
};

int main() {
    return 0;
}
