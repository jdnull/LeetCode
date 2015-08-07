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
#include <stack>

using namespace std;

class Solution {
public:
    // not my code, dfs, fast
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
    
    // not my code, DP,
    /*
         dp[i][j][l] means whether s2.substr(j,l) is a scrambled string of s1.substr(i,l) or not.
     */
//    bool isScramble(string s1, string s2) {
//        int len=s1.size();
//        bool dp[100][100][100]={false};
//        for (int i=len-1;i>=0;i--)
//            for (int j=len-1;j>=0;j--) {
//                dp[i][j][1]=(s1[i]==s2[j]);
//                for (int l=2;i+l<=len && j+l<=len;l++) {
//                    for (int n=1;n<l;n++) {
//                        dp[i][j][l]|=dp[i][j][n]&&dp[i+n][j+n][l-n];
//                        dp[i][j][l]|=dp[i][j+l-n][n]&&dp[i+n][j][l-n];
//                    }
//                }
//            }
//        return dp[0][0][len];
//    }
    
//    bool isScramble(string s1, string s2) {
//        bool ret = true;
//        size_t n = s1.length();
//        if (n > 0) // if s1 is empty, return true
//        {
//            // Dynamic Programming:
//            // eq[first1][first2][len] == true iff s1[first1 ... first1+len) == s2[first2 ... first2+len)
//            vector<vector<vector<bool> > > eq
//            (n, vector<vector<bool>>(n, vector<bool>(n + 1, false))); // initialize: all false
//            
//            // initialize: eq[first1][first2][1] = true iff s1[first1] == s2[first2]
//            for (int first1 = 0; first1 < n; ++first1)
//            {
//                for (int first2 = 0; first2 < n; ++first2)
//                {
//                    eq[first1][first2][1] = (s1[first1] == s2[first2]);
//                }
//            }
//            
//            // dp: eq[first1][first2][len] = true iff two substrings are both matched.
//            for (size_t len = 2; len <= n; ++len)
//            {
//                for (size_t first1 = 0; first1 + len <= n; ++first1)
//                {
//                    for (size_t first2 = 0; first2 + len <= n; ++first2)
//                    {
//                        for (size_t len1 = 1; len1 < len; ++len1)
//                        {
//                            size_t len2 = len - len1;
//                            
//                            // two substrings are not swapped
//                            if (eq[first1][first2][len1] && eq[first1 + len1][first2 + len1][len2])
//                            {
//                                eq[first1][first2][len] = true;
//                            }
//                            
//                            // two substrings are swapped
//                            if (eq[first1][first2 + len2][len1] && eq[first1 + len1][first2][len2])
//                            {
//                                eq[first1][first2][len] = true;
//                            }
//                        }
//                    }
//                }
//            }
//            ret = eq[0][0][n];
//        }
//        return ret;
//    }
};

int main() {
    Solution s;
    cout << s.isScramble("rabibt", "rabbit") << endl;
}