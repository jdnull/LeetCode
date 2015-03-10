//
//  main.cpp
//  LeetCodeTest
//
//  Created by JD on 15/3/10.
//  Copyright (c) 2015年 Ahrodite. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if ((n == 0) || (k <= 0))
        {
            return;
        }
        
        k = k % n;
        
        int i;
        for (i = 0; i < n/2; i++) {
            swap(nums, i, n-i-1);
        }
        for (i = 0; i < k/2; i++) {
            swap(nums, i, k-i-1);
        }
        for (i = 0; i < (n-k)/2; i++) {
            swap(nums, k+i, n-i-1);
        }
    }
    
    void swap(int nums[], int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
    void printNums(int nums[], int n) {
        for (int i = 0; i < n ; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    int n = 6;
    int k = 11;
    
    int nums[6] = {1,2,3,4,5,6};
    
    Solution s;
    s.rotate(nums, n, k);
    s.printNums(nums, n);
    
    return 0;
}