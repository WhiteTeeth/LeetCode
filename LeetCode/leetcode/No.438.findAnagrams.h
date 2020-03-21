//
//  No.438.findAnagrams.h
//  LeetCode
//
//  438. 找到字符串中所有字母异位词
//  https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_438_findAnagrams_h
#define No_438_findAnagrams_h

#include <string>

#define MAX_ALPHA_NUM (26)

bool isEqual(int *key, int *subStr) {
    for (int i = 0; i < MAX_ALPHA_NUM; i++) {
        if (key[i] != subStr[i]) return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};
    int key[MAX_ALPHA_NUM] = {0};
    for (char c : p) {
        key[c - 'a'] ++;
    }
    int pLen = p.length();
    vector<int> result;
    int subStr[MAX_ALPHA_NUM] = {0};
    for (int i = 0; i < pLen; i++) {
        subStr[s[i] - 'a'] ++;
    }
    
    if (isEqual(key, subStr)) {
        result.push_back(0);
    }
    
    for (int i = pLen; i < s.length(); i++) {
        subStr[s[i] - 'a'] ++;
        subStr[s[i - pLen] - 'a'] --;
        if (isEqual(key, subStr)) {
            result.push_back(i - pLen + 1);
        }
    }
    return result;
}

#endif /* No_438_findAnagrams_h */
