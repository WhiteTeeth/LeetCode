//
//  No.240.searchMatrix.h
//  LeetCode
//
//  240. 搜索二维矩阵 II
//  https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
//  Created by baiya on 2020/3/19.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_240_searchMatrix_h
#define No_240_searchMatrix_h

#include <vector>

// TODO 二分查找优化
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }

    return false;
}

#endif /* No_240_searchMatrix_h */
