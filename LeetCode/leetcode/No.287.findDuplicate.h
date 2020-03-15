//
//  No.287.findDuplicate.h
//  LeetCode
//
//  287. 寻找重复数
//  https://leetcode-cn.com/problems/find-the-duplicate-number/
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_287_findDuplicate_h
#define No_287_findDuplicate_h

#include <vector>

// TODO Floyd 算法
// https://qastack.cn/cs/10360/floyds-cycle-detection-algorithm-determining-the-starting-point-of-cycle
// TODO 二分查找
int findDuplicate(vector<int>& nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    int ptr1 = nums[0];
    int ptr2 = tortoise;
    while (ptr1 != ptr2) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    return ptr1;
}

void testFindDuplicate() {
    vector<int> nums = {1,4,1,3,2,5,3};
    int result = findDuplicate(nums);
}

#endif /* No_287_findDuplicate_h */
