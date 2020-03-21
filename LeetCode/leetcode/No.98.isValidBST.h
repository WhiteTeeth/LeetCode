//
//  No.98.isValidBST.h
//  LeetCode
//
//  98. 验证二叉搜索树
//  https://leetcode-cn.com/problems/validate-binary-search-tree/
//  Created by baiya on 2020/3/21.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_98_isValidBST_h
#define No_98_isValidBST_h

#inlclude "Utils.h"

bool isValidBST(TreeNode* root, long min, long max) {
    if (!root) {
        return true;
    }
    if (root->val <= min || root->val >= max) return false;
    return isValidBST(root->left, min, root->val)
        && isValidBST(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    if (!root) return true;
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

#endif /* No_98_isValidBST_h */
