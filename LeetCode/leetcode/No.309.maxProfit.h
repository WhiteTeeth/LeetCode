//
//  No.309.maxProfit.h
//  LeetCode
//
//  309. 最佳买卖股票时机含冷冻期
//  https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//  Created by baiya on 2020/3/11.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_309_maxProfit_h
#define No_309_maxProfit_h

#include <vector>

// 基于状态机的动态规划
int maxProfit(vector<int>& prices) {

    int length = prices.size();
    if(length < 2) return 0;
        int dp[3] = {0};    // 0 持股，1不持股，2冻结
        dp[0] = -prices[0];
        dp[1] = dp[2] = 0;
        int preStock = dp[0];
        int preCash = dp[1];
        for (int i = 1; i < length; i++) {
            dp[0] = max(preStock, dp[2] - prices[i]);
            dp[1] = max(preCash, preStock + prices[i]);
            dp[2] = preCash;
            preCash = dp[1];
            preStock = dp[0];
    }
    return max(dp[1], dp[2]);
    
}

#endif /* No_309_maxProfit_h */
