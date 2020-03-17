//
//  No.46.permute.h
//  LeetCode
//
//  46. 全排列
//  https://leetcode-cn.com/problems/permutations/
//  Created by baiya on 2020/3/18.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_46_permute_h
#define No_46_permute_h

#include <vector>

void permuteItem(vector<vector<int>>& result, vector<int> nums, vector<int>& item, int len) {
    if (nums.empty()) {
        result.push_back(item);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        item[len - nums.size()] = nums[i];
        vector<int> tmp(nums);
        tmp.erase(tmp.begin()+i);
        permuteItem(result, tmp, item, len);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> item(nums.size(), 0);
    permuteItem(result, nums, item, nums.size());
    return result;
}

#endif /* No_46_permute_h */
