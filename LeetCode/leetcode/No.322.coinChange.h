//
//  No.322.coinChange.h
//  LeetCode
//
//  322. 零钱兑换
//  https://leetcode-cn.com/problems/coin-change/
//  Created by baiya on 2020/3/6.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_322_coinChange_h
#define No_322_coinChange_h

#include <vector>

// TODO 更优算法

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount+1, 0);
    for (int i = 1; i < amount+1; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] == i) {
                dp[i] = 1;
                break;
            }
            if (coins[j] < i && dp[i - coins[j]]) {
                if (dp[i]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                } else {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }
    return dp[amount] ? dp[amount] : -1;
}

#endif /* No_322_coinChange_h */
