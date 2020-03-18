//
//  No.215.findKthLargest.h
//  LeetCode
//
//  Created by baiya on 2020/3/18.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_215_findKthLargest_h
#define No_215_findKthLargest_h

#include <vector>
#include <queue>

// TODO 手写有序链表算法
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> q;
    for(auto it:nums){
        q.push(it);
        if(q.size()>k) q.pop();
    }
    return q.top();
}

#endif /* No_215_findKthLargest_h */
