//
//  No.239.maxSlidingWindow.h
//  LeetCode
//
//  239. 滑动窗口最大值
//  https://leetcode-cn.com/problems/sliding-window-maximum/
//  Created by baiya on 2020/3/1.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_239_maxSlidingWindow_h
#define No_239_maxSlidingWindow_h

#include <deque>
#include <vector>
#include "Utils.h"

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> ideq;
    vector<int> result; // 存放下标
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (!ideq.empty() && ideq.front() < i + 1 - k) {
            ideq.pop_front();
        }
        while (!ideq.empty() && nums[i] > nums[ideq.back()]) {
            ideq.pop_back();
        }
                
        ideq.push_back(i);
        if (i >= k -1) {
            result.push_back(nums[ideq.front()]);
        }
    }
    return result;
}

void testNo239() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 8;
    vector<int> result = maxSlidingWindow(nums, k);
    printVector(result);
    k = 1;
    result = maxSlidingWindow(nums, k);
    printVector(result);
}



#endif /* No_239_maxSlidingWindow_h */
