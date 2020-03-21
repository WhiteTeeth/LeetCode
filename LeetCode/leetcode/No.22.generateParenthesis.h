//
//  No.22.generateParenthesis.h
//  LeetCode
//
//  22. 括号生成
//  https://leetcode-cn.com/problems/generate-parentheses/submissions/
//  Created by baiya on 2020/3/21.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_22_generateParenthesis_h
#define No_22_generateParenthesis_h

#include <string>

void append(vector<string>& result, string str, int n, int leftIndex, int leftCnt) {
    if (leftIndex == n) {
        for (int i = 0; i < leftCnt; i++) {
            str += ')';
        }
        result.push_back(str);
        return;
    }
    if (leftIndex < n) {
        append(result, str + '(', n, leftIndex + 1, leftCnt + 1);
    }
    if (leftCnt > 0) {
        append(result, str + ')', n, leftIndex, leftCnt-1);
    }
    
}

vector<string> generateParenthesis(int n) {
    if (n == 0) return {};
    vector<string> result;
    append(result, "(", n, 1, 1);
    return result;
}

void testGenerateParenthesis()
{
    int input = 3;
    vector<string> result = generateParenthesis(input);
    for (string i : result) {
        std::cout << i << std::endl;
    }
}

#endif /* No_22_generateParenthesis_h */
