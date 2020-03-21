//
//  No.621.leastInterval.h
//  LeetCode
//
//  621. 任务调度器
//  https://leetcode-cn.com/problems/task-scheduler/
//  Created by baiya on 2020/3/21.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_621_leastInterval_h
#define No_621_leastInterval_h

#include <vector>

// TODO 算法优化
int leastInterval(vector<char>& tasks, int n) {
    int taskCnt[26] = {0};
    for (int i = 0; i < tasks.size(); i++) {
        taskCnt[tasks[i] - 'A']++;
    }
    sort(taskCnt, taskCnt + 26);
    int max_val = taskCnt[25] - 1, idle_slots = (taskCnt[25] - 1) * n;
    for (int i = 24; i >= 0 && taskCnt[i] > 0; i--) {
        idle_slots -= min(taskCnt[i], max_val);
    }
    return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
}

#endif /* No_621_leastInterval_h */
