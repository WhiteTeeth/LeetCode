//
//  ValidUtf8.h
//  CPlusTest
//
//  Created by baiya on 2020/2/24.
//  Copyright © 2020 engleliu. All rights reserved.
//

#ifndef ValidUtf8_h
#define ValidUtf8_h

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

bool validUtf8() {
    int data[3] = {189, 128, 1};
    int minArr[4] = {0x80, 0xC0, 0xE0, 0xF0};
    int maxArr[4] = {0xC0, 0xE0, 0xF0, 0xF8};
    int size = 3;
    int bLen = 0;
    for (int i = size - 1; i > -1; i-- ) {
        int d = data[i];
        if (d < 0x80) {
            if (bLen) {
                return false;
            }
            continue;
        } else if (d >= 0x80 && d < 0xc0 && i != 0 ) {
            bLen ++;
            continue;
        } else if (bLen < 4 && d >= minArr[bLen] && d < maxArr[bLen]) {
            bLen = 0;
        } else {
            return false;
        }
    }
    return bLen == 0;
}

#endif /* ValidUtf8_h */
