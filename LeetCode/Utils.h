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
#include <stack>
#include <string>
#include <sstream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

TreeNode *convert2Tree(vector<int> nums) {
    TreeNode *node = new TreeNode(nums[0]);
    stack<TreeNode*> nodes;
    nodes.push(node);
    for (int i = 1; i < nums.size();) {
        TreeNode *curNode = nodes.top();
        nodes.pop();
        int left = nums[i++];
        curNode->left = new TreeNode(left);
        nodes.push(curNode->left);
        if (i < nums.size()) {
            int right = nums[i++];
            curNode->right = new TreeNode(right);
            nodes.push(curNode->right);
        }
    }
    return node;
}

#endif /* Utils_h */
