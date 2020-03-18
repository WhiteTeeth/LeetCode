//
//  No.102.levelOrder.h
//  LeetCode
//
//  102. 二叉树的层次遍历
//  https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
//  Created by baiya on 2020/3/19.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_102_levelOrder_h
#define No_102_levelOrder_h

#include <vector>
#include <queue>
#include "Utils.h"

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> level;
    level.push(root);
    queue<TreeNode*> nextLevel;
    vector<int> item;
    while (!nextLevel.empty() || !level.empty()) {
        TreeNode *cur = level.front();
        level.pop();
        item.push_back(cur->val);
        if(cur->left) nextLevel.push(cur->left);
        if(cur->right) nextLevel.push(cur->right);
        while(level.empty() && !nextLevel.empty()) {
            level = nextLevel;
            nextLevel = queue<TreeNode*>();
            
            result.push_back(item);
            item = vector<int>();
        }
    }
    result.push_back(item);
    return result;
}

void testLevelOrder()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = levelOrder(root);
    
}

#endif /* No_102_levelOrder_h */
