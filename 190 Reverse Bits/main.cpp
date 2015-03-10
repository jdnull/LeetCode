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

int main(int argc, const char * argv[]) {
    uint32_t n = 2;
    
    // my code
    int binary[32] = {0};
    int count = 0;
    
    binary[count++] = n % 2;
    int quotient = n / 2;
    while(quotient != 0) {
        binary[count++] = quotient % 2;
        quotient /= 2;
    }
    
    uint32_t ret = 0;
    for(count = 31; count >= 0; count--) {
        ret += binary[count] * pow(2, 31-count);
    }
    
    cout << ret << endl;
    
    // other's code
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    cout << n << endl;
    
    return 0;
}