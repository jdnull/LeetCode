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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> vv;
        vector<int> v;
        int sum = 0;
        combination(vv, v, sum, 1, k, n);
        return vv;
    }
    
    void combination(vector<vector<int>>& vv, vector<int> v, int sum, int start, int k, int n) {
        if (k == 0 && sum == n) {
            vv.push_back(v);
            return;
        }
        for (int i = start; i < 10; i++) {
            v.push_back(i);
            sum += i;
            combination(vv, v, sum, i+1, k-1, n);
            sum -= i;
            v.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> vv = s.combinationSum3(5, 25);
    
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}