//
//  No.300.lengthOfLIS.h
//  LeetCode
//
//  300. 最长上升子序列
//  https://leetcode-cn.com/problems/maximum-product-subarray/
//  Created by baiya on 2020/3/12.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_300_lengthOfLIS_h
#define No_300_lengthOfLIS_h

#include <vector>


// 动态规划，时间复杂度 o(n^2)
int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    int *dp = new int[size];
    dp[0] = 1;
    int result = 1;
    for (int i = 1; i < size; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}

// o(ln(n))的解法
// https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/

void testLengthOfLIS()
{
    vector<int> input = {10,9,2,5,3,7,101,18};
    int result = lengthOfLIS(input);
    assert(result == 4);
    input = {10,9,2,5,3,7,101,18,19};
    result = lengthOfLIS(input);
    assert(result == 5);
    input = {10};
    result = lengthOfLIS(input);
    assert(result == 1);
    input = {4,10,4,3,8,9};
    result = lengthOfLIS(input);
    assert(result == 3);
    input = {1,3,6,7,9,4,10,5,6};
    result = lengthOfLIS(input);
    assert(result == 6);
}

#endif /* No_300_lengthOfLIS_h */
