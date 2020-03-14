//
//  No.5.longestPalindrome.h
//  LeetCode
//
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_5_longestPalindrome_h
#define No_5_longestPalindrome_h

#include <string>

// TODO 马拉车算法，不懂
// https://www.cxyxiaowu.com/2665.html
// 中心扩散法
int palindromeLen(string s, int centerL, int centerR) {
    int l = centerL, r = centerR;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        r ++;
        l --;
    }
    return r - l - 1;
}

string longestPalindrome(string s) {
    if (s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = palindromeLen(s, i, i);
        int len2 = palindromeLen(s, i, i+1);
        int len = max(len1, len2);
        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }

    }
    return s.substr(start, end - start + 1);
}

void testLongestPalindrome()
{
    string input = "babad";
    string result = longestPalindrome(input);
    assert(result == "bab");
    input = "";
    result = longestPalindrome(input);
    assert(result == "");
    input = "baabad";
    result = longestPalindrome(input);
    assert(result == "baab");
    input = "b";
    result = longestPalindrome(input);
    assert(result == "b");
}

#endif /* No_5_longestPalindrome_h */
