//
//  No.739.dailyTemperatures.h
//  LeetCode
//
//  739. 每日温度
//  https://leetcode-cn.com/problems/daily-temperatures/
//  Created by baiya on 2020/3/19.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_739_dailyTemperatures_h
#define No_739_dailyTemperatures_h

#include <vector>
#include <stack>
#include "Utils.h"

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> st;
    vector<int> result(T.size(), 0);
    for (int i = 0; i < T.size(); i++) {
        while (!st.empty()) {
            int last = st.top();
            if (T[last] < T[i]) {
                result[last] = i - last;
                st.pop();
            } else {
                break;
            }
        }
        st.push(i);
    }
    return result;
}

void testDailyTemperatures() {
    vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(input);
    printVector(result);
}

#endif /* No_739_dailyTemperatures_h */
