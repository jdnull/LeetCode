#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // not my code, simpler
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vv;
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
            backtracking(vv, v, candidates, target-candidates[i], i+1);
            v.pop_back();
            
            while(i < candidates.size()-1 && candidates[i] == candidates[i+1]) {
                i++; // skip duplicate element
            }
        }
    }
};

#define COUNT 8
int main() {
    int a[COUNT] = {10,1,2,7,6,1,1,5};
    vector<int> candidates(a, &a[COUNT]);
    Solution s;
    vector<vector<int> > vv = s.combinationSum2(candidates, 8);
    for (vector<vector<int> >::iterator it0 = vv.begin(); it0 != vv.end(); it0++) {
        for (vector<int>::iterator it1 = it0->begin(); it1 != it0->end(); it1++) {
            cout << *it1 << " ";
        }
        cout << endl;
    }
}
