//
//  No.55.canJump.h
//  LeetCode
//
//  55. 跳跃游戏
//  https://leetcode-cn.com/problems/jump-game/
//  Created by baiya on 2020/3/17.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_55_canJump_h
#define No_55_canJump_h

#include <vector>

bool canJump(vector<int>& nums) {
    if (nums.empty()) return true;
    int maxStep = nums[0];
    int size = (int)nums.size();
    for (int i = 1; i < size-1; i++) {
        if (i <= maxStep) {
            maxStep = max(maxStep, i + nums[i]);
            if (maxStep >= size -1) return true;
        } else {
            return false;
        }
    }
    return maxStep >= size -1;
}

void testCanJump()
{
    vector<int> input = {2,3,1,1,4};
    bool result = canJump(input);
    assert(result == true);
    input = {3,2,1,0,4};
    result = canJump(input);
    assert(result == false);
    input = {3,2,0,1,4};
    result = canJump(input);
    assert(result == true);
    input = {1,1};
    result = canJump(input);
    assert(result == true);
}

#endif /* No_55_canJump_h */
