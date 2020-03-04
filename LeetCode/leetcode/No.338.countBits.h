//
//  No.338.countBits.h
//  LeetCode
//
//  338. 比特位计数
//  https://leetcode-cn.com/problems/counting-bits/
//  Created by baiya on 2020/3/5.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_338_countBits_h
#define No_338_countBits_h

#include <vector>

vector<int> countBits(int num) {
    vector<int> result(num+1);
    result[0] = 0;
    for (int i = 0; i <= num; i++) {
        if (i % 2 == 0) {
            result[i] = result[i/2];
        } else {
            result[i] = result[i-1] + 1;
        }
    }
    return result;
}

#endif /* No_338_countBits_h */
