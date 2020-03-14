//
//  No.152.maxProduct.h
//  LeetCode
//
//  152. 乘积最大子序列
//  https://leetcode-cn.com/problems/maximum-product-subarray/
//  Created by baiya on 2020/3/14.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_152_maxProduct_h
#define No_152_maxProduct_h

#include <vector>

// 穷举法，超时
//int maxProduct(vector<int>& nums) {
//    unsigned long len = nums.size();
//    vector<vector<int>> dp(len, vector<int>(len , 1));
//    dp[0][0] = nums[0];
//    int max = nums[0];
//    for (int i = 0; i < len; i++) {
//        dp[i][0] = nums[i];
//        max = std::max(max, dp[i][0]);
//    }
//
//    for (int i = 1; i < len; i++) {
//        for (int j = 1; j <= i; j ++) {
//            dp[i][j] = dp[i-1][j-1] * nums[i];
//            max = std::max(max, dp[i][j]);
//        }
//    }
//    return max;
//}

int maxProduct(vector<int>& nums) {
    int imax = 1, imin = 1, max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0){
            int tmp = imax;
            imax = imin;
            imin = tmp;
        }
        imax = std::max(imax*nums[i], nums[i]);
        imin = std::min(imin*nums[i], nums[i]);
        
        max = std::max(max, imax);
    }
    return max;
}

void testMaxProduct() {
    vector<int> input = {2,3,-2,4};
    int result = maxProduct(input);
    assert(result == 6);
    input = {2,3,-2,4,-2};
    result = maxProduct(input);
    assert(result == 96);
    input = {2,3,0,-2,4,-2};
    result = maxProduct(input);
    assert(result == 16);
    input = {0,2};
    result = maxProduct(input);
    assert(result == 2);
}

#endif /* No_152_maxProduct_h */
