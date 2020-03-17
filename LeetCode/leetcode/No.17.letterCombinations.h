//
//  No.17.letterCombinations.h
//  LeetCode
//
//  17. 电话号码的字母组合
//  https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
//  Created by baiya on 2020/3/17.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_17_letterCombinations_h
#define No_17_letterCombinations_h

#include <string>

void combinations(string digits, vector<string>& result, string& item, int digIndex) {
    vector<string> boards = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (digIndex == digits.length()) {
        result.push_back(item);
        return;
    }
    int num = digits[digIndex] - '0' - 2;
    for (int bIndex = 0; bIndex < boards[num].length(); bIndex ++) {
        item[digIndex] = boards[num][bIndex];
        combinations(digits, result, item, digIndex+1);
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) return {};
    vector<string> result;
    string item(digits.length(), ' ');
    combinations(digits, result, item, 0);
    return result;
}

void testLetterCombinations()
{
    string input = "23";
    vector<string> result = letterCombinations(input);
    
}

#endif /* No_17_letterCombinations_h */
