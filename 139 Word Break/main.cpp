#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code,
    // dp(i) respects to whether s[0,i] can be segmented
    // “dp(i) = dp(j) && s[j, i) in dict, 0 <= j < i”
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> dp;
        dp.resize(s.length()+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
    return 0;
}
