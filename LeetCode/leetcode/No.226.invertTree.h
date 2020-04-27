//
//  No.226.invertTree.h
//  LeetCode
//
//  206. 反转链表
//  https://leetcode-cn.com/problems/reverse-linked-list/
//  Created by baiya on 2020/4/28.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_226_invertTree_h
#define No_226_invertTree_h

#include "Utils.h"

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// TODO 非递归法

#endif /* No_226_invertTree_h */
