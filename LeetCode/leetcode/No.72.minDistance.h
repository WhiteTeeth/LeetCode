//
//  No.72.minDistance.h
//  LeetCode
//  No.72. 编辑距离
//  https://leetcode-cn.com/problems/edit-distance/
//  Created by baiya on 2020/2/27.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_72_minDistance_h
#define No_72_minDistance_h

int minDistance(string w1, string w2) {
    int n = w1.size(), m = w2.size();
    int dp[w1.size()+1][w2.size()+1];
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = i;//i个字符转化为0个字符 只能一直删i次
    for(int j = 0; j <= m; j++) dp[0][j] = j;//0个字符转化为j个字符 只能一直插入j次
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i][j-1],dp[i-1][j])+1;//插入 删除 时
            dp[i][j] = min(dp[i][j],dp[i-1][j-1] + (w1[i-1]==w2[j-1] ? 0:1));//替换时
        }
    }
    return dp[n][m];
}


void testMinDistance() {
    int step = minDistance("horse", "ros");
//    assert(step == 3);
//    step = minDistance("", "");
//    assert(step == 0);
//    step = minDistance("horse", "horse");
//    assert(step == 0);
//    step = minDistance("hore", "horse");
//    assert(step == 1);
//    step = minDistance("horue", "horse");
//    assert(step == 1);
//    step = minDistance("horue", "horse");
//    assert(step == 1);
//    step = minDistance("intention", "execution");
//    assert(step == 5);
    step = minDistance("dinitrophenylhydrazine", "acetylphenylhydrazine");
    NSLog(@"testMinDistance success!");
}


#endif /* No_72_minDistance_h */
