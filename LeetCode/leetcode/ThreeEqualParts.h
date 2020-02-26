//
//  ThreeEqualParts.h
//  CPlusTest
//
//  Created by baiya on 2020/2/24.
//  Copyright © 2020 engleliu. All rights reserved.
//

#ifndef ThreeEqualParts_h
#define ThreeEqualParts_h
#include <vector>
#include <string>

using namespace std;

vector<int> threeEqualParts() {
    vector<int> A = {1, 0, 1, 0, 1};
    // 遍历查找1的个数并缓存位置
    vector<int> indexVec;
    int size = A.size();
    for (int i = 0; i < size; i++) {
        if (A[i] == 1) {
            indexVec.push_back(i);
        }
    }
    int sum = indexVec.size();
    if (sum % 3 != 0) {
        return {-1, -1};
    }
    if (sum == 0) {
        return {0 , 1};
    }
    // 三等分确认位置
    int firStart = indexVec[0];
    int secStart = indexVec[sum / 3];
    int thiStart = indexVec[sum * 2 / 3];
    // 判断长度是否合法
    if (secStart - firStart < size - thiStart ||
        thiStart - secStart < size - thiStart) {
            return {-1, -1};
    }
    // 判断数值是否相同
    int itemLen = sum / 3;
    int firDistance = secStart - firStart;
    int secDistance = thiStart - firStart;
    for (int j = 0; j < itemLen; j++) {
        if (indexVec[j] + firDistance == indexVec[j + sum / 3] &&
            indexVec[j] + secDistance == indexVec[j + 2 * sum / 3]) {
                continue;
            } else {
                return {-1, -1};
            }
    }
    int len = size - thiStart;
    int firIndex = firStart + len - 1;
    int secIndex = secStart + len;
    return {firIndex, secIndex};
}


#endif /* ThreeEqualParts_h */
