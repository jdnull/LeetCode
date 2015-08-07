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
    // not my code, dp
    /*
         DP table represents if s3 is interleaving at (i+j)th position when s1 is at ith position, and s2 is at jth position. 0th position means empty string.
         
         So if both s1 and s2 is currently empty, s3 is empty too, and it is considered interleaving. If only s1 is empty, then if previous s2 position is interleaving and current s2 position char is equal to s3 current position char, it is considered interleaving. similar idea applies to when s2 is empty. when both s1 and s2 is not empty, then if we arrive i, j from i-1, j, then if i-1,j is already interleaving and i and current s3 position equal, it s interleaving. If we arrive i,j from i, j-1, then if i, j-1 is already interleaving and j and current s3 position equal. it is interleaving.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        
        bool table[s1.length()+1][s2.length()+1];
        
        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                if(i==0 && j==0)
                    table[i][j] = true;
                else if(i == 0)
                    table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
        
        return table[s1.length()][s2.length()];
    }
    
    // my code, dfs, time limit exceed
//    bool isInterleave(string s1, string s2, string s3) {
//        int s1Count = 0, s2Count = 0;
//        return dfs(0, s1Count, s1, 0, s2Count, s2, 0, s3);
//    }
//    
//    bool dfs(int s1Begin, int& s1Count, string& s1,
//             int s2Begin, int& s2Count, string& s2,
//             int s3Begin, string& s3) {
//        if (s1Count + s2Count == s3.length()) {
//            return true;
//        }
//        for (int i = s3Begin; i < s3.length(); i++) {
//            size_t s1TBegin = s1.find(s3[i], s1Begin);
//            size_t s2TBegin = s2.find(s3[i], s2Begin);
//            if (s1TBegin != string::npos) {
//                s1Count++;
//                if (dfs(s1TBegin+1, s1Count, s1, s2Begin, s2Count, s2, i+1, s3)) {
//                    return true;
//                } else {
//                    s1Count--;
//                }
//            }
//            if (s2TBegin != string::npos) {
//                s2Count++;
//                if (dfs(s1Begin, s1Count, s1, s2TBegin+1, s2Count, s2, i+1, s3)) {
//                    return true;
//                } else {
//                    s2Count--;
//                }
//            }
//        }
//        return false;
//    }
};

int main() {
    Solution s;
//    cout << s.isInterleave("ab", "cd", "abdc") << endl;
//    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
//    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << s.isInterleave("cacccaa", "acccaacabbbab", "accccaaaccccabbaabab") << endl;
}