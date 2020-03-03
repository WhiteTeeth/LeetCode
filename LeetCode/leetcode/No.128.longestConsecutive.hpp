//
//  No.128.longestConsecutive.h
//  LeetCode
//
//  128. 最长连续序列
//  https://leetcode-cn.com/problems/longest-consecutive-sequence/
//  Created by baiya on 2020/3/3.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_128_longestConsecutive_h
#define No_128_longestConsecutive_h

#include <vector>
#include <map>
#include <unordered_map>

// 解法二，动态规划，真tm nb
// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/c-dong-tai-gui-hua-fu-za-du-on-by-izeuwy/
int longestConsecutive2(vector<int>& nums) {
    unordered_map<int, int> dp;
    int ret = 0;
    for(auto &x : nums) {
        if(!dp[x]) dp[x - dp[x - 1]] = dp[x + dp[x + 1]] = dp[x] = dp[x - 1] + dp[x + 1] + 1;
        ret = max(ret, dp[x]);
    }
    return ret;
}

// 解法一，双map 映射
int longestConsecutive(vector<int>& nums) {
    // 有重复序列
    map<int, int> seMap;  // start : end
    map<int, int> esMap;  // end : start
    
    int longest = 0;
    for (int i : nums) {
        if (!seMap.count(i)) {
            int start = i, end = i;
            if (esMap.count(i-1)) {
                start = esMap[i-1];
            }
            if (seMap.count(i+1)) {
                end = seMap[i+1];
            }
            seMap[start] = end;
            esMap[end] = start;
            seMap[i] = end;
            esMap[i] = start;
            longest = max(longest, end - start + 1);
        }
    }
    return longest;
}

void testLongestConsecutive()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    int result = longestConsecutive(nums);
    assert(result == 9);
    nums = {9,8,7,6,5,4,3,2,1};
    result = longestConsecutive(nums);
    assert(result == 9);
    nums = {1,2,3,9,8,7,4,5,6};
    result = longestConsecutive(nums);
    assert(result == 9);
    nums = {100, 4, 200, 1, 3, 2};
    result = longestConsecutive(nums);
    assert(result == 4);
}

#endif /* No_128_longestConsecutive_h */
