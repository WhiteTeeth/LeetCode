//
//  No.64.minPathSum.h
//  LeetCode
//
//  64. 最小路径和
//  https://leetcode-cn.com/problems/minimum-path-sum/
//  Created by baiya on 2020/3/5.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_64_minPathSum_h
#define No_64_minPathSum_h

#include <vector>

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size()==0)return 0;
    for(int i =0 ;i<grid.size(); i++)
    {
        for(int j=0;j<grid[0].size(); j++)
        {
            if(i==0&&j==0)continue;
            else if(i==0) grid[i][j] = grid[i][j-1]+grid[i][j];
            else if(j==0) grid[i][j] = grid[i-1][j] +grid[i][j];
            else grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}

void testMinPathSum()
{
    vector<vector<int>> grid({{1,3,1}, {1,5,1}, {4,2,1}});
    int re = minPathSum(grid);
    assert(re == 7);
}

#endif /* No_64_minPathSum_h */
