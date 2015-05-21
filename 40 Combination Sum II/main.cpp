#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num) {
        if(target==0) {
            res.push_back(local);
            return;
        }
        else {
            for(int i = order;i<num.size();i++) { // iterative component
                if(num[i]>target) return;
                ////// this condition is hard to set /////
                if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination
                //
                local.push_back(num[i]),
                findCombination(res,i+1,target-num[i],local,num); // recursive componenet
                local.pop_back();
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
