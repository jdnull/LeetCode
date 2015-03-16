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
#include <vector>
#include <map>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode *a = l1, *b = l2, *pre = NULL;
        int addToHigh = 0;
        while(a != NULL && b != NULL) {
            int t = a->val + b->val + addToHigh;
            a->val = t % 10;
            if (t > 9) {
                addToHigh = 1;
            } else {
                addToHigh = 0;
            }
            pre = a;
            a = a->next;
            b = b->next;
        }
        
        if (a != NULL) {
            while (addToHigh != 0 && a != NULL) {
                int t = a->val + addToHigh;
                a->val = t % 10;
                if (t > 9) {
                    addToHigh = 1;
                } else {
                    addToHigh = 0;
                }
                pre = a;
                a = a->next;
            }
        }
        
        if (b != NULL) {
            pre->next = b;
            while (addToHigh != 0 && b != NULL) {
                int t = b->val + addToHigh;
                b->val = t % 10;
                if (t > 9) {
                    addToHigh = 1;
                } else {
                    addToHigh = 0;
                }
                pre = b;
                b = b->next;
            }
        }
        
        if (addToHigh > 0) {
            pre->next = new ListNode(1);
        }
        
        return l1;
    }
};

int main() {
//    Solution s;
//    int a[5] = {-1,-2,-3,-4,-5};
//    vector<int> input(&a[0], &a[5]);
//    vector<int> v = s.twoSum(input, -8);
//    cout << v[0] << " " << v[1] << endl;
    return 0;
}
