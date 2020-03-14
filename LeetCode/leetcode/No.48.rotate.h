//
//  No.48.rotate.h
//  LeetCode
//
//  48. 旋转图像
//  https://leetcode-cn.com/problems/rotate-image/
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_48_rotate_h
#define No_48_rotate_h

#include <vector>

// 执行用时 : 0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗 : 8.5 MB, 在所有 C++ 提交中击败了 100.00% 的用户
void rotate(vector<vector<int>>& matrix) {
    int tmp[4] = {0};
    int len = matrix.size()-1;
    for (int y = 0; y <= len/2; y++ ) {  // y
        for (int x = 0; x < (len+1)/2; x++) {   // x
            tmp[1] = matrix[x][len-y];
            matrix[x][len-y] = matrix[y][x];
            tmp[2] = matrix[len-y][len-x];
            matrix[len-y][len-x] = tmp[1];
            tmp[3] = matrix[len-x][y];
            matrix[len-x][y] = tmp[2];
            matrix[y][x] = tmp[3];
        }
    }
}

void testRotate()
{
    vector<vector<int>> input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(input);
    printf("end");
}

#endif /* No_48_rotate_h */
