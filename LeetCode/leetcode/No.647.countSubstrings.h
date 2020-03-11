//
//  No.647.countSubstrings.h
//  LeetCode
//
//  647. 回文子串
//  https://leetcode-cn.com/problems/palindromic-substrings/
//  Created by baiya on 2020/3/11.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_647_countSubstrings_h
#define No_647_countSubstrings_h

#include <string>

// 方案一、动态规划
// isPalindromeString 实现有问题导致耗时巨久
//bool isPalindromeString(string s, int start, int end) {
//    while (start < end) {
//        if (s[start++] != s[end--]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int countSubstrings(string s) {
//    int length = s.length();
//    if (length == 0) return 0;
//    int dp[1001] = {0};
//    dp[0] = 1;
//    for (int i = 1; i < length; i ++) {
//        dp[i] = dp[i-1] + 1;
//        for (int j = 0; j < i; j++) {
//            dp[i] += isPalindromeString(s, j, i);
//        }
//    }
//    return dp[length-1];
//}

// 方案二，中心扩散法
int substring(string s, int start, int end){
    int sum = 0;
    while(start>=0 && end<s.size() && s[start]==s[end]){
        start--;
        end++;
        sum++;
    }
    return sum;
}

int countSubstrings(string s) {
    int sum = 0;
    for(int i=0; i<s.size(); i++){
        sum += substring(s, i, i);
        sum += substring(s, i, i+1);
    }
    return sum;
}

void testCountSubstrings()
{
    string s = "abc";
    int re = countSubstrings(s);
    assert(re == 3);
    s = "aaa";
    re = countSubstrings(s);
    assert(re == 6);
    s = "aba";
    re = countSubstrings(s);
    assert(re == 4);
    s = "a";
    re = countSubstrings(s);
    assert(re == 1);
    
}

#endif /* No_647_countSubstrings_h */
