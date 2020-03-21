//
//  No.79.exist.h
//  LeetCode
//
//  79. 单词搜索
//  https://leetcode-cn.com/problems/word-search/
//  Created by baiya on 2020/3/21.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_79_exist_h
#define No_79_exist_h

#include <vector>
#include <string>

// 用行参不要用实参
bool exist(vector<vector<char>>& board, string& word, int index, int row, int column) {
    if (board[row][column] != word[index]) {
        return false;
    }
    if (index == word.length() - 1) {
        return true;
    }
    char tmp = board[row][column];
    board[row][column] = 0;
    if ((column - 1 >= 0 && exist(board, word, index + 1, row, column - 1))
        || ((column + 1 <= board[0].size() - 1 && exist(board, word, index + 1, row, column + 1)))
        || ((row - 1 >= 0 && exist(board, word, index + 1, row - 1, column)))
        || ((row + 1 <= board.size() - 1 && exist(board, word, index + 1, row + 1, column))))
        return true;
    board[row][column] = tmp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if (word.length() == 0) return true;
    if (board.empty()) return false;
    int row = board.size();
    int column = board[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (exist(board, word, 0, i, j)) return true;
        }
    }
    return false;
}

#endif /* No_79_exist_h */
