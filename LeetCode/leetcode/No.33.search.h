//
//  No.33.search.h
//  LeetCode
//
//  33. 搜索旋转排序数组
//  https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
//  Created by baiya on 2020/3/16.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_33_search_h
#define No_33_search_h

#include <vector>

int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = (int)nums.size() -1 , middle = 0;
    if (target < nums[0] && target > nums.back()) return -1;
    bool bigger = target >= nums[0];
    while (left < right) {
        middle = (left + right) / 2;
        if (target == nums[middle]) return middle;
        if (target < nums[middle]) {
            if (bigger) right = middle - 1;
            else if (nums[middle] >= nums[0]) left = middle + 1;
            else right = middle - 1;
        } else if (target > nums[middle]) {
            if (bigger && nums[middle] >= nums[0]) left = middle + 1;
            else if (bigger) right = middle - 1;
            else left = middle + 1;
        }
    }
    return nums[left] == target ? left : -1;
}

void testSearch()
{
    vector<int> input = {4,5,6,8,0,1,2};
    int target = 6;
    int result = search(input, target);
    assert(result == 2);
    target = 1;
    result = search(input, target);
    assert(result == 5);
    target = 3;
    result = search(input, target);
    assert(result == -1);
    target = 7;
    result = search(input, target);
    assert(result == -1);
    target = 9;
    result = search(input, target);
    assert(result == -1);
    input = {0,1,2,4,5,6,8};
    target = 4;
    result = search(input, target);
    assert(result == 3);
    input = {0,1,2,4,5,6,8};
    target = 3;
    result = search(input, target);
    assert(result == -1);
    input = {1,2,4,5,6,8};
    target = 0;
    result = search(input, target);
    assert(result == -1);
    input = {0,1,2,4,5,6,8};
    target = 9;
    result = search(input, target);
    assert(result == -1);
    input = {0,1,2,4,5,6,8};
    target = 8;
    result = search(input, target);
    assert(result == 6);
    input = {0,8};
    target = 8;
    result = search(input, target);
    assert(result == 1);
    input = {0,8};
    target = 0;
    result = search(input, target);
    assert(result == 0);
    input = {8,0};
    target = 0;
    result = search(input, target);
    assert(result == 1);
    input = {8,0};
    target = 8;
    result = search(input, target);
    assert(result == 0);
}

#endif /* No_33_search_h */
