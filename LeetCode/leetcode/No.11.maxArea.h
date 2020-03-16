//
//  No.11.maxArea.h
//  LeetCode
//
//  11. 盛最多水的容器
//  https://leetcode-cn.com/problems/container-with-most-water/
//  Created by baiya on 2020/3/16.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_11_maxArea_h
#define No_11_maxArea_h

#include <vector>

// TODO 双指针法
int maxArea(vector<int>& height) {
    int result = 0;
    int start = 0, end = (int)height.size() - 1;
    while (start < end) {
        int area = (end - start) * std::min(height[start], height[end]);
        result = std::max(result, area);
        if (height[start] > height[end]) {
            end --;
        } else {
            start ++;
        }
    }
    return result;
}

void testMaxArea()
{
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    int result = maxArea(input);
    assert(result == 49);
    input = {1,8};
    result = maxArea(input);
    assert(result == 1);
    input = {1,5,15,8};
    result = maxArea(input);
    assert(result == 10);
}

#endif /* No_11_maxArea_h */
