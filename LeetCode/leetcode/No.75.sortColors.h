//
//  No.75.sortColors.h
//  LeetCode
//
//  75. 颜色分类
//  https://leetcode-cn.com/problems/sort-colors/
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_75_sortColors_h
#define No_75_sortColors_h

#include <vector>
#include "Utils.h"

void sortColors(vector<int>& nums) {
    
    unsigned long end = nums.size();
    for (int i = 0; i < end; ) {
        if (nums[i] == 2) {
            nums.erase(nums.begin() + i);
            nums.push_back(2);
            end --;
        } else if (nums[i] == 0) {
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin(), 0);
            i++;
        } else {
            i++;
        }
    }
}

void testSortColors()
{
    vector<int> nums = {2,0,2,1,1,0};
    printVector(nums);
    sortColors(nums);
    printVector(nums);
    nums = {};
    printVector(nums);
    sortColors(nums);
    printVector(nums);
    nums = {1,2,0};
    printVector(nums);
    sortColors(nums);
    printVector(nums);
    printf("sort colors end");
}

#endif /* No_75_sortColors_h */
