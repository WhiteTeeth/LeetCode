//
//  No.279.numSquares.h
//  LeetCode
//
//  279. 完全平方数
//  https://leetcode-cn.com/problems/perfect-squares/
//  Created by baiya on 2020/3/6.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_279_numSquares_h
#define No_279_numSquares_h

#include <vector>


/*
 *  https://leetcode-cn.com/problems/perfect-squares/solution/si-ping-fang-c-by-sidney-4/
 *  Lagrange's Four Square theorem：每个正整数均可表示为4个整数（包括0）的平方和，所以只有四种可能结果，即[1,2,3,4]
    Legendre's three-square theorem：非4^a(8b+7)型的正整数都可以用三个整数的平方和表示，所以对于可以写成4^a(8b+7）类型的n，其结果只能为4
*/
int numSquares(int n) {
       while(n%4==0) n/=4;
       if(n%8==7) return 4;
       for(int a=0;a*a<=n;++a)
       {
           int b=sqrt(n-a*a);
           if(a*a+b*b==n) {
               return !!a+!!b;
           }
       }
       return 3;
}

int numSquares(int n) {
    vector<int> dp(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        dp[i] = n;
        for (int j = 1; i - j * j >= 0; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

#endif /* No_279_numSquares_h */
