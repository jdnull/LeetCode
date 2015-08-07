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
    // not my code
    /*
         Use f[i][j] to represent the shortest edit distance between word1[0,i) and word2[0, j). Then compare the last character of word1[0,i) and word2[0,j), which are c and d respectively (c == word1[i-1], d == word2[j-1]):
         
         if c == d, then : f[i][j] = f[i-1][j-1]
         
         Otherwise we can use three operations to convert word1 to word2:
         
         (a) if we replaced c with d: f[i][j] = f[i-1][j-1] + 1;
         
         (b) if we added d after c: f[i][j] = f[i][j-1] + 1;
         
         (c) if we deleted c: f[i][j] = f[i-1][j] + 1;
         
         Note that f[i][j] only depends on f[i-1][j-1], f[i-1][j] and f[i][j-1], therefore we can reduce the space to O(n) by using only the (i-1)th array and previous updated element(f[i][j-1]).
     */
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        
        vector<int> f(l2+1, 0);
        for (int j = 1; j <= l2; ++j)
            f[j] = j;
        
        for (int i = 1; i <= l1; ++i)
        {
            int prev = i;
            for (int j = 1; j <= l2; ++j)
            {
                int cur;
                if (word1[i-1] == word2[j-1]) {
                    cur = f[j-1];
                } else {
                    cur = min(min(f[j-1], prev), f[j]) + 1;
                }
                
                f[j-1] = prev;
                prev = cur;
            }
            f[l2] = prev;
        }
        return f[l2];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("rabbbit", "rabbit") << endl;
}