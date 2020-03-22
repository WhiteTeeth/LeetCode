//
//  No.337.rob.h
//  LeetCode
//
//  337. 打家劫舍 III
//  https://leetcode-cn.com/problems/house-robber-iii/
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_337_rob_h
#define No_337_rob_h

#include "Utils.h"

// 递归法，超时
//int rob(TreeNode* root) {
//    if (!root) return 0;
//    int money = root->val;
//    if (root->left) {
//        money += rob(root->left->left) + rob(root->left->right);
//    }
//    if (root->right) {
//        money += rob(root->right->left) + rob(root->right->right);
//    }
//    return max(money, rob(root->left) + rob(root->right));
//}

// TODO : 动态规划 || 后序遍历
void rob_task(TreeNode* root, int *val1, int *val2)
{
    if(root == NULL){
        *val1 = 0;
        *val2 = 0;
        return;
    }
    int result1, result2, result3, result4;

    rob_task(root->right, &result1, &result2);
    rob_task(root->left, &result3, &result4);

    *val1 = root->val + result2 + result4;
    *val2 = max(result1, result2) + max(result3, result4);
}
int rob(TreeNode* root) {
    int res1,res2;
    rob_task(root,&res1,&res2);
    return max(res1,res2);
}

#endif /* No_337_rob_h */
