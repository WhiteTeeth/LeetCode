//
//  17.21.Solution.h
//  42. 接雨水
//  https://leetcode-cn.com/problems/volume-of-histogram-lcci/
//  https://leetcode-cn.com/problems/trapping-rain-water/
//  Created by baiya on 2020/2/25.
//  Copyright © 2020 engleliu. All rights reserved.
//

#ifndef _7_21_Solution_h
#define _7_21_Solution_h
#include <vector>
#include <string>
using namespace std;

int trap(vector<int>& height) {
    
    int size = height.size();
    int left = 0;
    int right = size - 1;
    int cubeLeft = 0;
    int cubeRight = 0;
    int leftP = 0;
    int rightP = size - 1;
    int result = 0;
    while (left <= right) {
        if (height[leftP] < height[left]) {
            cubeLeft += height[leftP];
        } else {
            result += std::max(std::min(height[left], height[leftP]) * (leftP - left - 1) - cubeLeft, 0);
            cubeLeft = 0;
            left = leftP;
        }
        if (height[rightP] < height[right]) {
            cubeRight += height[rightP];
        } else {
            result += std::max(std::min(height[right], height[rightP]) * (rightP - right - 1) - cubeRight, 0);
            cubeRight = 0;
            right = rightP;
        }
        leftP ++;
        rightP --;

    }
    return result;
}

#endif /* _7_21_Solution_h */
