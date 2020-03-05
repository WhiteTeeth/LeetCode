//
//  No.416.canPartition.h
//  LeetCode
//
//  416. 分割等和子集
//  https://leetcode-cn.com/problems/partition-equal-subset-sum/
//  Created by baiya on 2020/3/5.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_416_canPartition_h
#define No_416_canPartition_h

#include <vector>
#include <numeric>

// 0-1 背包问题
// 元素比较少时，也可以用递归搜索
bool canPartition(vector<int>& nums) {
    int size = (int)nums.size();
    int sum = accumulate(nums.begin(), nums.end(),0);
    if (sum & 0x1) return false;
    int target = sum >> 1;
    
    vector<vector<int>> dp(size, vector<int>(target+1,0));
    if (nums[0] <= target) dp[0][nums[0]] = true;
    
    for (int i = 1; i < size; i++) {
        if (nums[i] > target) return false;
        if (nums[i] == target) return true;
        for (int j = 0; j <= target; j++) {
            if (j == nums[i]) {
                dp[i][j] = true;
            } else if (nums[i] < j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
        if (dp[i][target]) return true;
    }
    return false;
}

#endif /* No_416_canPartition_h */
