//
//  No.94.inorderTraversal.h
//  LeetCode
//
//  94. 二叉树的中序遍历
//  https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
//  Created by baiya on 2020/3/18.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_94_inorderTraversal_h
#define No_94_inorderTraversal_h

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TODO 迭代算法完成，栈辅助
void middleOrder(vector<int> &result, TreeNode* node)
{
    if (!node) return;
    middleOrder(result, node->left);
    result.push_back(node->val);
    middleOrder(result, node->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    middleOrder(result, root);
    return result;
}

#endif /* No_94_inorderTraversal_h */
