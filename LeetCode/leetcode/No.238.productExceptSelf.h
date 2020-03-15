//
//  No.238.productExceptSelf.h
//  LeetCode
//
//  238. 除自身以外数组的乘积
//  https://leetcode-cn.com/problems/product-of-array-except-self/
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_238_productExceptSelf_h
#define No_238_productExceptSelf_h

#include <vector>
#include "Utils.h"

// 左右乘积列表
// TODO O(1) 的空间复杂度
vector<int> productExceptSelf(vector<int>& nums) {
    int len = (int)nums.size();
    vector<int> left(len, 1);
    vector<int> right(len, 1);
    vector<int> result(len, 1);
    for (int i = 0; i < len-1; i++) {
        left[i+1] = left[i] * nums[i];
    }
    for (int j = len-1; j > 0; j--) {
        right[j-1] = right[j] * nums[j];
    }
    for (int k = 0; k < len; k ++) {
        result[k] = left[k] * right[k];
    }
    return result;
}

void testProductExceptSelf()
{
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    printVector(result);
    nums = {1,2,3,4};
    result = productExceptSelf(nums);
    printVector(result);
    nums = {2,2};
    result = productExceptSelf(nums);
    printVector(result);
}

#endif /* No_238_productExceptSelf_h */
