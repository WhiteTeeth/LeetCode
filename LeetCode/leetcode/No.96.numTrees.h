//
//  No.96.numTrees.h
//  LeetCode
//
//  96. 不同的二叉搜索树
//  https://leetcode-cn.com/problems/unique-binary-search-trees/
//  Created by baiya on 2020/3/5.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_96_numTrees_h
#define No_96_numTrees_h

int numTrees(int n) {
    int *dp = new int[n+1];
    memset(dp, 0, sizeof(int)*(n+1));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

void testNumTrees()
{
    int input = 3;
    int result = numTrees(input);
    assert(result == 5);
}

#endif /* No_96_numTrees_h */
