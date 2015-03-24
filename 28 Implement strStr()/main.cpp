#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
// This method's time consuming too much, need to learn KMP algorithm.
//    int strStr(char *haystack, char *needle) {
//        if (*haystack == '\0' && *needle == '\0') {
//            return 0;
//        }
//        
//        int ret = -1;
//        int index = 0;
//        char *start, *p;
//        while (haystack[index] != '\0') {
//            start = &haystack[index];
//            bool match = true;
//            for (p = needle; *p != '\0'; p++, start++) {
//                if (*start != *p) {
//                    match = false;
//                    break;
//                }
//            }
//            if (match) {
//                ret = index;
//                break;
//            } else {
//                index++;
//            }
//        }
//        return ret;
//    }

// kmp algorithm
    int strStr(char *haystack, char *needle) {
        string text = haystack;
        string pattern = needle;
        if (pattern.length() == 0) {
            return 0;
        }
        if (text.length() < pattern.length()) {
            return -1;
        }
        vector<int> prefix = getPrefixArray(pattern);
        int n = -1;
        for (int i = 0; i < text.length(); i++) {
            while (n > -1 && pattern[n+1] != text[i]) {
                n = prefix[n];
            }
            if (pattern[n+1] == text[i]) {
                n++;
            }
            if (n+1 == pattern.length()) {
                return i-n;
            }
        }
        
        return -1;
    }
    
    vector<int> getPrefixArray(string pattern) {
        vector<int> prefix;
        prefix.push_back(-1);
        int k = -1;
        for (int n = 1; n < pattern.length(); n++) {
            while (k > -1 && pattern[k+1] != pattern[n]) {
                k = prefix[k];
            }
            if (pattern[k+1] == pattern[n]) {
                k++;
            }
            prefix.push_back(k);
        }
        return prefix;
    }
};

int main() {
    string str = "mississippi";
    char* haystack = const_cast<char*>(str.c_str());
    string find = "issipi";
    char* needle = const_cast<char*>(find.c_str());
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
    
    return 0;
}
