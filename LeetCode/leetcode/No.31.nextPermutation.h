//
//  No.31.nextPermutation.h
//  LeetCode
//
//  31. 下一个排列
//  https://leetcode-cn.com/problems/next-permutation/
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_31_nextPermutation_h
#define No_31_nextPermutation_h

#include <vector>
#include "Utils.h"

void nextPermutation(vector<int>& nums) {

    int target = -1;
    for (int i = (int)nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            target = i;
            break;
        }
    }
    std::reverse(nums.begin() + target + 1, nums.end());
    if (target >= 0) {
        for (int i = target + 1; i < nums.size(); i++) {
            if (nums[i] > nums[target]) {
                swap(nums[i], nums[target]);
                break;
            }
        }
    }
    
}

void testNextPermutation()
{
    vector<int> input = {2, 3, 1};
    nextPermutation(input);
    printVector(input);
}

#endif /* No_31_nextPermutation_h */
