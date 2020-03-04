//
//  No.78.subsets.h
//  LeetCode
//
//  78. 子集
//  https://leetcode-cn.com/problems/subsets/
//  解题：https://zhuanlan.zhihu.com/p/37502243
//  Created by baiya on 2020/3/5.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_78_subsets_h
#define No_78_subsets_h

#include <vector>

vector<vector<int>> subsets(vector<int>& nums) {
    int size = (int)nums.size();
    int l = pow(2, size);
    vector<vector<int>> result;
    for (int i = 0; i < l; i++) {
        // i 转成二进制，为1
        vector<int> tmp;
        for (int j = 0; j < size; j++) {
            if ( (1 << j) & i) {
                tmp.push_back(nums[j]);
            }
        }
        result.push_back(tmp);
    }
    
    return result;
}

#endif /* No_78_subsets_h */
