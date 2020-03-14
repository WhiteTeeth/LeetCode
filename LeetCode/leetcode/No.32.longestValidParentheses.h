//
//  No.32.longestValidParentheses.h
//  LeetCode
//
//  32. 最长有效括号
//  https://leetcode-cn.com/problems/longest-valid-parentheses/
//  Created by baiya on 2020/3/3.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_32_longestValidParentheses_h
#define No_32_longestValidParentheses_h
#include <string>
#include <stack>

// TODO 未通过
int longestValidParentheses(string s) {
    // 栈操作
    int max = 0;
    int curMax = 0;
    int lastMax = 0;
    stack<char> st;
    for (string::iterator it = s.begin(); it!= s.end(); it++) {
        if (*it == '(') {
            st.push(*it);
        } else if (!st.empty()) {
            if (st.top() == '(') {
                st.pop();
                curMax += 2;
                if (st.empty()) {
                    lastMax += curMax;
                    curMax = 0;
                }
            } else {
                // error
                while(!st.empty()) st.pop();
                max = std::max(std::max(lastMax, curMax), max);
                curMax = 0;
                lastMax = 0;
            }
        } else {
            max = std::max(std::max(lastMax, curMax), max);
            curMax = 0;
            lastMax = 0;
        }
    }
    max = std::max(std::max(lastMax, curMax), max);
    return max;
}

void testLongestValidParentheses()
{
    string s = ")()())";
    int longest = longestValidParentheses(s);
    assert(longest == 4);
    s = ")()()";
    longest = longestValidParentheses(s);
    assert(longest == 4);
    s = ")(())";
    longest = longestValidParentheses(s);
    assert(longest == 4);
    s = "()(()";
    longest = longestValidParentheses(s);
    assert(longest == 2);
    s = "(()(((()";
    longest = longestValidParentheses(s);
    assert(longest == 2);
}

#endif /* No_32_longestValidParentheses_h */
