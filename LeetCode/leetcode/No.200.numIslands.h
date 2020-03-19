//
//  No.200.numIslands.h
//  LeetCode
//
//  200. 岛屿数量
//  https://leetcode-cn.com/problems/number-of-islands/
//  Created by baiya on 2020/3/19.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_200_numIslands_h
#define No_200_numIslands_h

#include <vector>

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1' && grid[i-1][j] == '0' && grid[i][j-1] == '0') {
                count ++;
            }
        }
    }
    return count;
}

#endif /* No_200_numIslands_h */
