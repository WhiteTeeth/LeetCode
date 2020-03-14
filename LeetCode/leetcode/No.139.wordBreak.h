//
//  No.139.wordBreak.h
//  LeetCode
//
//  139. 单词拆分
//  https://leetcode-cn.com/problems/word-break/
//  Created by baiya on 2020/3/13.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_139_wordBreak_h
#define No_139_wordBreak_h

#include <vector>
#include <string>

bool wordBreak(string s, vector<string>& wordDict) {
    
    unsigned long length = s.length();
    int *dp = new int[length+1]; // index 为s长度
    memset(dp, 0, sizeof(int)*(length+1));
    dp[0] = 1;
    for (int i = 1; i <= length; i++) {
        for (int j = 0 ; j < wordDict.size(); j++) {
            unsigned long curLen = wordDict[j].length();
            if (curLen <= i) {
                dp[i] = dp[i-curLen] && (wordDict[j] == (s.substr(length - i, curLen)));
                if (dp[i]) {
                    break;
                }
            }
        }
    }
    return dp[length];
}

void testWordBreak()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = wordBreak(s, wordDict);
    assert(result);
    s = "leetcdecode";
    wordDict = {"leet", "code"};
    result = wordBreak(s, wordDict);
    assert(!result);
}

#endif /* No_139_wordBreak_h */
