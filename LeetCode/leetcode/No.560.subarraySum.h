//
//  No.560.subarraySum.h
//  LeetCode
//
//  560. 和为K的子数组
//  https://leetcode-cn.com/problems/subarray-sum-equals-k/
//  Created by baiya on 2020/3/17.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_560_subarraySum_h
#define No_560_subarraySum_h

#include <vector>

// 双指针法
//int subarraySum(vector<int>& nums, int k) {
//    if (nums.empty()) return 0;
//    int begin = 0, end = 0, sum = nums[0] + 1000, count = 0;
//    while (end < nums.size()) {
//        int target = k + (end - begin + 1) * 1000;
//        if (sum == target) {
//            count ++;
//            end ++;
//            if (end >= nums.size()) {
//                break;
//            }
//            sum = sum + nums[end] + 1000;
//            if (nums[begin] == 0) {
//                sum = sum - nums[begin] - 1000;
//                begin ++;
//                count ++;
//            }
//        } else if (sum < target) {
//            end ++;
//            sum = sum + nums[end] + 1000;
//        } else {
//            sum = sum - nums[begin] - 1000;
//            begin ++;
//        }
//    }
//    return count;
//
//}
// TODO 前缀和
int subarraySum(vector<int>& nums, int k) {
    int sum = 0, ans = 0;
    unordered_map<int,int> mp; // value : count
    mp[0] = 1;
    for(int i: nums){
        sum += i;
        if(mp.find(sum-k) != mp.end()) ans += mp[sum-k];
        mp[sum] ++;
    }
    return ans;
}


void testSubarraySum()
{
    vector<int> nums = {1,1,1};
    int target = 2;
    int result = subarraySum(nums, target);
    assert(result == 2);
    nums = {1,1,1};
    target = 4;
    result = subarraySum(nums, target);
    assert(result == 0);
    nums = {1,0,1,1,1};
    target = 2;
    result = subarraySum(nums, target);
    assert(result == 4);
    nums = {};
    target = 0;
    result = subarraySum(nums, target);
    assert(result == 0);
    nums = {0, 0, 0, 0, 0};
    target = 0;
    result = subarraySum(nums, target);
    assert(result == 15);
}

#endif /* No_560_subarraySum_h */
