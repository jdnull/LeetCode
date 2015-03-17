#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
// this method time consuming too much, O(n^2)
//    int lengthOfLongestSubstring(string s) {
//        int maxSubStrinLen = 0;
//        list<char> substring;
//        for (string::iterator it = s.begin(); it != s.end(); it++) {
//            substring.erase(substring.begin(), findCharacter(substring, *it));
//            substring.push_back(*it);
//            if (maxSubStrinLen < substring.size()) {
//                maxSubStrinLen = substring.size();
//            }
//        }
//        
//        return maxSubStrinLen;
//    }
//    
//    list<char>::iterator findCharacter(list<char>& l, char ch) {
//        list<char>::reverse_iterator it = l.rbegin();
//        for (; it != l.rend(); it++) {
//            if (*it == ch) {
//                return it.base();
//            }
//        }
//        return it.base();
//    }
    
    // here solution comes from leetcode, O(1) space, O(n) time
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(129,-1);
        int res =0, last = -1, sSize = s.size();
        int i;
        
        if(sSize>0)
        {
            for( i=0;i<sSize; i++)
            {
                if(pos[s[i]] == -1)
                    pos[s[i]] = i; // if it is the first time that character s[i] occures
                else
                { // if it is a new repeating case
                    if(pos[s[i]] > last)
                    { // if the first index of this repeating case is larger than that of the last processed repeating case
                        res = max(res, i - last - 1); // update the maximum non-repeating substring length
                        last = pos[s[i]]; // update the starting index of the current non-repeating substring
                    }
                    pos[s[i]] = i; // update the most recent index of s[i]
                }
            }
            res = max(res, sSize - last - 1); // at last, we need to check the current non-repeating substring end at the end of s
            
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcacbh") << endl;
    return 0;
}
