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
