//
//  No.221.maximalSquare.h
//  LeetCode
//
//  221. 最大正方形
//  https://leetcode-cn.com/problems/maximal-square/
//  Created by baiya on 2020/3/14.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_221_maximalSquare_h
#define No_221_maximalSquare_h

#include <vector>

// dp(i, j)=min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1
int maximalSquare(vector<vector<char>>& matrix) {

    unsigned long row = matrix.size();
    if (row == 0) return 0;
    unsigned long column = matrix[0].size();
    if (column == 0) return 0;
    vector<vector<int>> dp(row, vector<int>(column, 0));
    
    int maxL = 0;
    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
            maxL = 1;
        }
    }
    for (int j = 0; j < column; j++) {
        if (matrix[0][j] == '1') {
            dp[0][j] = 1;
            maxL = 1;
        }
    }
    
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1])) + 1;
                maxL = std::max(maxL, dp[i][j]);
            }
        }
    }
    return maxL * maxL;
}

void testMaximalSquare()
{
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    int result = maximalSquare(matrix);
    assert(result == 4);
    matrix = {
        {'1'}
    };
    result = maximalSquare(matrix);
    assert(result == 1);
    matrix = {
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'}
    };
    result = maximalSquare(matrix);
    assert(result == 16);
    matrix = {};
    result = maximalSquare(matrix);
    assert(result == 0);
    matrix = {
        {'0','1'}
    };
    result = maximalSquare(matrix);
    assert(result == 1);
}

#endif /* No_221_maximalSquare_h */
