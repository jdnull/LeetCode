#include <iostream>

using namespace std;

class Solution {
public:
// this method cost too much time
//    string longestPalindrome(string s) {
//        for (int i = s.length(); i > 0; i--) {
//            for (int j = s.length()-i; j >= 0; j--) {
//                bool isExist = true;
//                for (int x = j, y = x+i-1; x <= (x+y)/2; x++, y--) {
//                    if (s[x] != s[y]) {
//                        isExist = false;
//                        break;
//                    }
//                }
//                if (isExist) {
//                    return s.substr(j, j+i);
//                }
//            }
//        }
//        
//        return s.substr(0,1);
//    }
    
    // this method still has improving space
    string longestPalindrome(string s) {
        string split = "#";
        string t = "#";
        for (int i = 0; i < s.length(); i++) {
            t += s.substr(i,1) + split;
        }
        
        int start = 0, end = 0;
        for (int mid = 0; mid < t.length(); mid++) {
            for (int i = mid+1, j = mid-1; j >= 0; i++, j--) {
                if (t[i] == t[j]) {
                    if (i-j > end-start) {
                        start = j;
                        end = i;
                    }
                } else {
                    break;
                }
            }
        }
        
        string ret = "";
        for (int i = start; i <= end; i++) {
            if (t[i] != '#') {
                ret += t.substr(i,1);
             }
        }
        
        return ret;
    }
};

int main() {
    Solution s;
//    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string str = "aaba";
    cout << s.longestPalindrome(str) << endl;
    
    return 0;
}
