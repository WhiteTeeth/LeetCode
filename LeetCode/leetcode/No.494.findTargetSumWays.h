//
//  No.494.findTargetSumWays.h
//  LeetCode
//
//  494. 目标和
//  https://leetcode-cn.com/problems/target-sum/
//  Created by baiya on 2020/3/10.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_494_findTargetSumWays_h
#define No_494_findTargetSumWays_h

#include<vector>


int findTargetSumWays(vector<int>& nums, int S) {
    int dp[20][2001] = {0};
    dp[0][1000-nums[0]] = 1;
    dp[0][1000+nums[0]] += 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int sum = -1000; sum < 1000; sum++) {
            if (dp[i - 1][sum + 1000] > 0) {
                dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
            }
        }
    }
    return S > 1000 ? 0 : dp[nums.size()-1][S + 1000];
}

// 遍历...耗时巨长
//int findT(vector<int>& nums, int S, int end) {
//    if (end == 0) return (nums[0] == S) + (nums[0] == -S);
//    return findT(nums, S - nums[end], end -1) + findT(nums, S+nums[end], end-1);
//}
//
//int findTargetSumWays(vector<int>& nums, int S) {
//    return findT(nums, S, nums.size()-1);
//}



void testFindTargetSumWays()
{
    vector<int> input = {1,1,1,1,1};
    int result = findTargetSumWays(input, 3);
    assert(result == 5);
    input = {1,0};
    result = findTargetSumWays(input, 1);
    assert(result == 2);
}

#endif /* No_494_findTargetSumWays_h */
