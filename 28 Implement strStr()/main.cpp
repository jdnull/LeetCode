//
//  main.cpp
//  LeetCodeTest
//
//  Created by JD on 15/3/10.
//  Copyright (c) 2015年 Ahrodite. All rights reserved.
//

//#include <iostream>
//#include <vector>
//#include <stack>
//#include <math.h>
//
//using namespace std;
//
//void printVector(vector<int>& v) {
//    for(vector<int>::iterator i = v.begin(); i != v.end(); i++) {
//        cout << *i << " ";
//    }
//    cout << endl;
//}
//
//class Solution {
//public:
//    struct Transaction{
//        int b;
//        int s;
//        int profit;
//    };
//    
//    int maxProfit(int k, vector<int> &prices) {
//        int b, s;
//        int n = prices.size();
//        vector<Transaction> transactions;
//        for (b = 0; b < n-1; b++) {
//            for (s = b+1; s < n; s++) {
//                Transaction t;
//                t.b = b;
//                t.s = s;
//                t.profit = prices[s] - prices[b];
//                transactions.push_back(t);
//            }
//        }
//        
//        
////        printVector(benifitMatrix);
////        cout << dimension2To1(n-1, 0, 1) << endl;
////        cout << dimension2To1(n-1, 0, 2) << endl;
////        cout << dimension2To1(n-1, 0, 3) << endl;
////        cout << dimension2To1(n-1, 1, 2) << endl;
////        cout << dimension2To1(n-1, 1, 3) << endl;
////        cout << dimension2To1(n-1, 2, 3) << endl;
//        return maxProfit;
//    }
//    
//    // map (row, col) to index of one dimension array, n means n*n size for the upper triangular matrix
//    int dimension2To1(int n, int col, int row) {
//        int x = 0;
//        for(int i = col; i > 0; i--) {
//            x += n;
//            n--;
//        }
//        return x+row-col-1;
//    }
//};
//
//int main(int argc, const char * argv[]) {
//    int a[4] = {3, 2, 5, 2};
//    vector<int> prices(&a[0], &a[4]);
////    printVector(prices);
//    
//    Solution s;
//    cout << s.maxProfit(4, prices) << endl;
//    return 0;
//}


////////////////////////////////////////////////////////////////

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
