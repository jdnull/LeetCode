#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // not my code, faster
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vv;
        if (candidates.size() == 0 || target < 0) {
            return vv;
        }
        vector<int> v;
        
        sort(candidates.begin(), candidates.end());
        
        backtracking(vv, v, candidates, target, 0);
        
        return vv;
    }
    
    void backtracking(vector<vector<int>> &vv, vector<int> v, vector<int>& candidates, int target, int level) {
        if (target == 0) {
            vv.push_back(v);
            return;
        }
        
        for(int i = level; i < candidates.size(); i++) {
            if (target-candidates[i] < 0) {
                return; // pruning, bigger value with higher index
            }
            v.push_back(candidates[i]);
            backtracking(vv, v, candidates, target-candidates[i], i);
            v.pop_back();
        }
    }

    // not my code, simpler, slower
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> vv;
    //     if (candidates.size() == 0 || target < 0) {
    //         return vv;
    //     }
    //     vector<int> v;
        
    //     sort(candidates.begin(), candidates.end());
        
    //     backtracking(vv, v, candidates, target, 0);
        
    //     return vv;
    // }
    
    // void backtracking(vector<vector<int>> &vv, vector<int> v, vector<int>& candidates, int target, int level) {
    //     if (target == 0) {
    //         vv.push_back(v);
    //         return;
    //     } else if (target < 0) {
    //         return;
    //     }
        
    //     for(int i = level; i < candidates.size(); i++) {
    //         v.push_back(candidates[i]);
    //         backtracking(vv, v, candidates, target-candidates[i], i);
    //         v.pop_back();
    //     }
    // }
    
    // my code, not simple
    // vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
        
    //     vector<vector<int> > vv;
    //     vector<int> v;

    //     subCombinationSum(candidates, vv, v, target);
        
    //     return vv;
    // }
    
    // void subCombinationSum(vector<int>& candidates, vector<vector<int> >& vv, vector<int>& v, int target) {
    //     if (target == 0) {
    //         vv.push_back(v);
    //         v.pop_back();
    //         return;
    //     }
    //     for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++) {
    //         if (v.size() > 0 && *it < v[v.size()-1]) {
    //             continue;
    //         }
    //         if (target - *it >= 0) {
    //             v.push_back(*it);
    //             subCombinationSum(candidates, vv, v, target - *it);
    //         } else {
    //             v.pop_back();
    //             return;
    //         }
    //     }
    //     if (!v.empty()) {
    //         v.pop_back();
    //     }
    // }
};

#define COUNT 4
int main() {
    int a[COUNT] = {2,3,6,7};
    vector<int> candidates(a, &a[COUNT]);
    Solution s;
    vector<vector<int> > vv = s.combinationSum(candidates, 7);
    for (vector<vector<int> >::iterator it0 = vv.begin(); it0 != vv.end(); it0++) {
        for (vector<int>::iterator it1 = it0->begin(); it1 != it0->end(); it1++) {
            cout << *it1 << " ";
        }
        cout << endl;
    }
}
