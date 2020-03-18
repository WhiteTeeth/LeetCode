//
//  Utils.h
//  LeetCode
//
//  Created by baiya on 2020/3/15.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printVector(vector<int> nums) {
    std::ostringstream oss;
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(oss, ","));
    std::cout << oss.str() << std::endl;
}

#endif /* Utils_h */
