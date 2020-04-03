//
//  No.50.myPow.h
//  LeetCode
//
//  50. Pow(x, n)
//  https://leetcode-cn.com/problems/powx-n/
//  Created by baiya on 2020/4/3.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_50_myPow_h
#define No_50_myPow_h

double myPow(double x, int n) {
    if (n == 1) return x;
    else if (n == 0) return 1.0;
    else if (n < 0) {
        x = 1.0 / x;
    }
    double re = myPow(x, (int)(n < 0 ? -(long)n : n) >> 1);
    return re * re * (n & 0x1 ? x : 1.0);
}

void testMyPow()
{
    assert(myPow(34.00515, -3) == 0.00003);
}

#endif /* No_50_myPow_h */
