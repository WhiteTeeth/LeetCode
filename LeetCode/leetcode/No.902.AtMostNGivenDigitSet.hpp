//
//  AtMostNGivenDigitSet.h
//  CPlusTest
//
//  902. 最大为 N 的数字组合
//  https://leetcode-cn.com/problems/numbers-at-most-n-given-digit-set/
//  Created by baiya on 2020/2/24.
//  Copyright © 2020 engleliu. All rights reserved.
//

#ifndef AtMostNGivenDigitSet_h
#define AtMostNGivenDigitSet_h
#include <vector>
#include <string>

using namespace std;

bool isContains(vector<string> D, string s, int& index) {
    unsigned int size = D.size();
    unsigned int start = 0, end = size - 1, mid = 0;
    if (s < D[start]) {
        index = -1;
        return false;
    }
    if (s > D[end]) {
        index = end;
        return false;
    }
    while (start != end - 1) {
        mid = (start + end) / 2;
        if (D[mid] == s) {
            index = mid;
            return true;
        } else if (D[mid] > s) {
            end = mid;
        } else {
            start = mid;
        }
    }
    if (s == D[start]) {
        index = start;
        return true;
    } else if (s == D[end]) {
        index = end;
        return true;
    } else {
        index = start;
        return false;
    }
}

int atMostNGivenDigitSet(vector<string>& D, int N) {
    // 该题实际为计算最多位的数量
    // 将 N 转为字符串
    std::string nStr = std::to_string(N);
    // 逐步取出每一位数字，找出其在对应D中的位置
    unsigned int size = nStr.size();
    unsigned int count = 0;
    for (int i = 0; i < size; i++) {
        // 二分查找
        int index;
        string c;
        c = nStr[i];
        bool contains = isContains(D, c, index);
        if (contains) {
            count += index * pow(D.size(), size - 1 - i);
            if (i == size - 1) {
                count += 1;
            }
            continue;
        } else {
            count += (index + 1) * pow(D.size(), size - 1 - i);
            break;
        }
    }
    // 如果该位置的数字与D中某一元素相等，则遍历下一位，依次类推
    // 计算每一位的数量，累加
    for (int i = 1; i < size; i++) {
        count += pow(D.size(), i);
    }
    // 输出结果
    return count;
}

#endif /* AtMostNGivenDigitSet_h */
