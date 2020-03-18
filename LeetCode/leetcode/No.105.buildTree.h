//
//  No.105.buildTree.h
//  LeetCode
//
//  105. 从前序与中序遍历序列构造二叉树
//  https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//  Created by baiya on 2020/3/19.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_105_buildTree_h
#define No_105_buildTree_h

#include <vector>
#include "Utils.h"

// TODO

TreeNode* buildSubTree(vector<int>& preorder,
                       vector<int>& inorder,
                       int& pos, int left, int right) {
    if (pos >= preorder.size()) return nullptr;
    
    int i = left;
    for (i = left; i <= right; ++i) {
        if (inorder[i] == preorder[pos]) break;
    }
    TreeNode* node = new TreeNode(preorder[pos]);
    if (left <= i-1) {
        node->left = buildSubTree(preorder, inorder, ++pos, left, i-1);
    }
    if (i+1 <= right) {
        node->right = buildSubTree(preorder, inorder, ++pos, i+1, right);
    }
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pos = 0;
    return buildSubTree(preorder, inorder, pos, 0, inorder.size()-1);
}

#endif /* No_105_buildTree_h */
