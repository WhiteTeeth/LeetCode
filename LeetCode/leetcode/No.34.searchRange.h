//
//  No.34.searchRange.h
//  LeetCode
//
//  34. 在排序数组中查找元素的第一个和最后一个位置
//  https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_34_searchRange_h
#define No_34_searchRange_h

#include <vector>
#include "Utils.h"

vector<int> searchRange(vector<int>& nums, int target) {
    
    int start = 0, end = (int)nums.size()-1, middle = 0;
    bool find = false;
    while (start <= end) {
        middle = (start + end) / 2;
        if (nums[middle] > target) {
            end = middle-1;
        } else if (nums[middle] < target) {
            start = middle+1;
        } else {
            find = true;
            break;
        }
    }
    if (!find) return {-1, -1};
    
    int left = middle, right = middle;
    int midL = 0, midR = 0;
    while (start < left) {
        midL = (start + left) / 2;
        if (nums[midL] < target) {
            start = midL + 1;
        }else {
            left = midL;
        }
    }
    while (right < end) {
        midR = (right + end + 1) / 2;
        if (nums[midR] > target) {
            end = midR - 1;
        } else {
            right = midR;
        }
    }
    return {left, right};
}

void testSearchRange()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    printVector(result);
    nums = {5,7,7,8,8,10};
    target = 6;
    result = searchRange(nums, target);
    printVector(result);
    nums = {};
    target = 6;
    result = searchRange(nums, target);
    printVector(result);
    nums = {6};
    target = 6;
    result = searchRange(nums, target);
    printVector(result);
    nums = {6,6};
    target = 6;
    result = searchRange(nums, target);
    printVector(result);
}

#endif /* No_34_searchRange_h */
