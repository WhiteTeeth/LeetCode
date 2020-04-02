//
//  No.406.reconstructQueue.h
//  LeetCode
//
//  406. 根据身高重建队列
//  https://leetcode-cn.com/problems/queue-reconstruction-by-height/
//  Created by baiya on 2020/4/2.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_406_reconstructQueue_h
#define No_406_reconstructQueue_h

#include <vector>

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    
    std::sort(people.begin(), people.end(), [](vector<int>& lp, vector<int>& rp){
            return lp[0] == rp[0] ? lp[1] < rp[1] : lp[0] > rp[0];});
    
    vector<vector<int>> result;
    for(auto i : people)
    {
        auto pos=result.begin();
        advance(pos,i[1]);
        result.insert(pos,i);
    }
    return result;
}

#endif /* No_406_reconstructQueue_h */
