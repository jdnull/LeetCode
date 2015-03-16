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

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
// this method "Time Limit Exceeded"
//        vector<int> v;
//        for (int i = 0; i < numbers.size(); i++) {
//            for (int j = i+1; j < numbers.size(); j++) {
//                if (target == numbers[i]+numbers[j]) {
//                    v.push_back(i+1);
//                    v.push_back(j+1);
//                }
//            }
//        }
//        return v;
        
        vector<int> v;
        map<int, vector<int> > m;
        for (int i = 0; i < numbers.size(); i++) {
            map<int, vector<int> >::iterator it = m.find(numbers[i]);
            if (it == m.end()) {
                vector<int> value;
                value.push_back(i+1);
                m[numbers[i]] = value;
//                m.insert(pair<int, vector<int> >(numbers[i], value));
            } else {
                it->second.push_back(i+1);
            }
        }
        
        for (map<int, vector<int> >::iterator it1 = m.begin(); it1 != m.end(); it1++) {
            map<int, vector<int> >::iterator it2 = m.find(target-(it1->first));
            if (it1 != it2) {
                if (it1 != m.end() && it2 != m.end()) {
                    if (it1->second[0] < it2->second[0]) {
                        v.push_back(it1->second[0]);
                        v.push_back(it2->second[0]);
                    } else {
                        v.push_back(it2->second[0]);
                        v.push_back(it1->second[0]);
                    }
                    break;
                }
            } else {
                if (it1->second.size() >= 2) {
                    if (it1->second[0] < it1->second[1]) {
                        v.push_back(it1->second[0]);
                        v.push_back(it1->second[1]);
                    } else {
                        v.push_back(it1->second[1]);
                        v.push_back(it1->second[0]);
                    }
                    break;
                }
            }
        }
        
        return v;
    }
};

int main() {
    Solution s;
    int a[5] = {-1,-2,-3,-4,-5};
    vector<int> input(&a[0], &a[5]);
    vector<int> v = s.twoSum(input, -8);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}
