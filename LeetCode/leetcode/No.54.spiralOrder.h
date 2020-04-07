//
//  No.54.spiralOrder.h
//  LeetCode
//
//  54. 螺旋矩阵
//  https://leetcode-cn.com/problems/spiral-matrix/
//  Created by baiya on 2020/4/8.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_54_spiralOrder_h
#define No_54_spiralOrder_h

#include <vector>

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    const int m = matrix.size();
    const int n = matrix[0].size();
    int leftX = 0, leftY = 0;
    int rightX = n - 1, rightY = m - 1;
    int curX = 0, curY = 0;
    vector<int> result;
    while (rightX >= leftX && rightY >= leftY) {
        result.push_back(matrix[curY][curX]);
        if (rightX == leftX && rightY == leftY) break;
        if (curY == leftY && curX < rightX) {
            curX ++; // 上 && 向右
        } else if (curY == leftY && curX == rightX) {
            curY ++; // 右上拐点
            if (curY > rightY) break;
        } else if (curX == rightX && curY < rightY) {
            curY ++; // 右 && 向下
        } else if (curX == rightX && curY == rightY) {
            curX --; // 右下拐点
            if (curX < leftX) break;
        } else if (curY == rightY && curX > leftX) {
            curX --; // 下 && 向左
        } else if (curY == rightY && curX == leftX) {
            curY --; // 左下拐点
            if (curY == leftY) break;
        } else if (curX == leftX && curY > leftY + 1) {
            curY --; // 左 && 向上
        } else if (curX == leftX && curY == leftY + 1) {
            curX ++; // 左上拐点
            rightX --;
            rightY --;
            leftX ++;
            leftY ++;
        }
    }
    return result;
}

#endif /* No_54_spiralOrder_h */
