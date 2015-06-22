#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    // cost too much time by recursive
//    int numTrees(int n) {
//        vector<int> v;
//        v.resize(n);
//        return dfs(v, n);
//    }
//    
//    int dfs(vector<int>& v, int n) {
//        if (n == 0) {
//            return 1;
//        }
//        
//        int count = 0;
//        for (int i = 1; i <= n; i++) {
//            count += dfs(v, i-1) * dfs(v, n-i);
//        }
//        v[n-1] = count;
//        return v[n-1];
//    }
    
    int numTrees(int n) {
        vector<int> v;
        v.resize(n+1, 0);
        v[0] = 1;
        v[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                v[i] += v[j] * v[i-j-1];
            }
        }
        return v[n];
    }
};

int main() {
    
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}
