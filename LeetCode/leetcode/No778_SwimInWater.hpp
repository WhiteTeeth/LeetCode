//
//  No778_SwimInWater.h
//  LeetCode
//  778. 水位上升的泳池中游泳
//  https://leetcode-cn.com/problems/swim-in-rising-water/
//  Created by baiya on 2020/2/27.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No778_SwimInWater_h
#define No778_SwimInWater_h
#include <vector>
#include <stack>
#include <set>
using namespace std;

bool isPossiable(int t, vector<vector<int>>& grid) {
    int mSeen[50][50] = {0};        // 缓存可以用栈、map 或者数组
    stack<int> mStack;
    mStack.push(0);
    mSeen[0][0] = 1;
    int N = (int)grid.size();
    int x[4] = {-1, 0, 1, 0}; // 左、上、右、下
    int y[4] = {0, -1, 0, 1};

    while (!mStack.empty()) {
        int node = mStack.top();
        mStack.pop();
        int r = node / N;
        int c = node % N;
        if (r == N - 1 && c == N - 1) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int cr = r + y[i];
            int cc = c + x[i];
            int ck = cr * N + cc;
            
            if (cr < 0 || cr >= N || cc < 0 || cc >= N) continue;
            if (grid[cr][cc] <= t && !mSeen[cr][cc]) {
                mSeen[cr][cc] = 1;
                mStack.push(ck);
            }
        }
    }
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    // 该题为在方格中找到一条线路，时间为该线路中的最大值
    int N = (int)grid.size();
    int start = grid[0][0];
    int end = N * N;
    int mid = 0;
    while (start < end) {
        mid = (start + end) / 2;
        if (isPossiable(mid, grid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

#endif /* No778_SwimInWater_h */
