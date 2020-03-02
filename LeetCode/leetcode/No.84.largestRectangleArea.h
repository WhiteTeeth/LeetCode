//
//  No.84.largestRectangleArea.h
//  LeetCode
//
//  84. 柱状图中最大的矩形
//  https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
//  Created by baiya on 2020/3/3.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_84_largestRectangleArea_h
#define No_84_largestRectangleArea_h
#include <vector>
#include <stack>

// 栈排序
// 继续优化耗时的方案：缩短数组取址的耗时
int largestRectangleArea(vector<int>& heights) {
    stack<int> area;
    area.push(-1);
    int largest = 0;
    int size = (int)heights.size();
    for (int i = 0; i < size; i++) {
        int t = area.top();
        while (t != -1 && heights[t] >= heights[i]) {
            area.pop();
            largest = max(largest, (i - area.top() - 1) * heights[t]);
            t = area.top();
        }
        area.push(i);
    }
    int t = area.top();
    while (-1 != t) {
        area.pop();
        largest = max(largest, (size - area.top() - 1) * heights[t]);
        t = area.top();
    }
    return largest;
}

void testLargestRectangleArea()
{
    vector<int> heights = {2,1,5,6,2,3};
    int result = largestRectangleArea(heights);
    assert(result == 10);
    heights = {2};
    result = largestRectangleArea(heights);
    assert(result == 2);
    heights = {2,3,4,5,6,5,4,3,2,1};
    result = largestRectangleArea(heights);
    assert(result == 21);
    heights = {2,3,4,5,6,5,4,3};
    result = largestRectangleArea(heights);
    assert(result == 21);
    heights = {7,6,5,4,3,2,1};
    result = largestRectangleArea(heights);
    assert(result == 16);
    printf("%d\n", result);
}

#endif /* No_84_largestRectangleArea_h */
