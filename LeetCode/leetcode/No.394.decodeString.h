//
//  No.394.decodeString.h
//  LeetCode
//
//  394. 字符串解码
//  https://leetcode-cn.com/problems/decode-string/
//  Created by baiya on 2020/3/21.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_394_decodeString_h
#define No_394_decodeString_h

#include <string>
#include <stack>
#include <pair>

typedef pair<int,string> pis;

string repeat(const string& str, int times) {
    string retString = "";
    for(int i = 0; i < times; ++i) retString += str;
    return retString;
}

string decodeString(string& s) {
    int repeatTims = 0;
    string res = "";
    vector<pis> vecStack;
    for(auto i : s) {
        if('0' <= i && i <= '9')  {
            repeatTims = (repeatTims*10)+(i-'0');
        }
        else if (i == '[') {
            vecStack.push_back({repeatTims,res});
            res = "";
            repeatTims = 0;
        }
        else if(i == ']') {
            pis tmp = vecStack[vecStack.size()-1];
            vecStack.pop_back();
            res = tmp.second + (tmp.first == 0 ? "" : repeat(res, tmp.first));
        }
        else res += i;
    }
    return res;
}
#endif /* No_394_decodeString_h */
