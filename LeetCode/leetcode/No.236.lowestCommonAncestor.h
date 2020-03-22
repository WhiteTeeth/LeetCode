//
//  No.236.lowestCommonAncestor.h
//  LeetCode
//
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_236_lowestCommonAncestor_h
#define No_236_lowestCommonAncestor_h

#include "Utils.h"

TreeNode *result;

bool lfs(TreeNode *root, TreeNode* p, TreeNode* q) {
    if (result) return true;
    if (!root) return 0;
    bool findL = lfs(root->left, p, q);
    bool findR = lfs(root->right, p, q);
    if (!result) {
        int count = findL + findR + (root == p || root == q);
        if (2 == count) {
            result = root;
        }
        return count > 0;
    }
    return true;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    lfs(root, p, q);
    return result;
}
#endif /* No_236_lowestCommonAncestor_h */
