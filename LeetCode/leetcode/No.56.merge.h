//
//  No.56.merge.h
//  LeetCode
//
//  56. 合并区间
//  https://leetcode-cn.com/problems/merge-intervals/
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_56_merge_h
#define No_56_merge_h

#include <vector>

// TODO 耗时优化
bool sortFunc (vector<int> i, vector<int> j) { return (i[0] < j[0]); }

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    vector<vector<int>> result;
    std::sort (intervals.begin(), intervals.end(), sortFunc);
    for (vector<int> item : intervals) {
        if (result.empty()) {
            result.push_back(item);
            continue;
        }
        vector<int> back = result.back();
        if (back[1] >= item[0]) {
            result[result.size()-1][1] = std::max(back[1], item[1]);
        } else {
            result.push_back(item);
        }
    }
    return result;
}

void testMerge()
{
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(input);
    printVector(result[0]);
}

#endif /* No_56_merge_h */
