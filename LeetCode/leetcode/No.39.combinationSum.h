//
//  No.39.combinationSum.h
//  LeetCode
//
//  39. 组合总和
//  https://leetcode-cn.com/problems/combination-sum/
//  Created by baiya on 2020/3/17.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_39_combinationSum_h
#define No_39_combinationSum_h

#include <vector>

// TODO 更优解
void combinationItem(vector<int> candidates,
                     int start,
                     int target,
                     vector<int>& cur,
                     vector<vector<int>>& ans)
{
    if (target == 0) {
        ans.push_back(cur);
        return;
    }
    if (start >= candidates.size()) return;
    int iNum = target / candidates[start];
    combinationItem(candidates, start+1, target, cur, ans);
    for (int i = 1; i <= iNum; i++) {
        cur.push_back(candidates[start]);
        combinationItem(candidates, start+1, target - candidates[start] * i, cur, ans);
    }
    for (int i = 1; i <= iNum; i++) {
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> cur;
    combinationItem(candidates, 0, target, cur, result);
    return result;
}

#endif /* No_39_combinationSum_h */
