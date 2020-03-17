//
//  No.114.flatten.h
//  LeetCode
//
//  114. 二叉树展开为链表
//  https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
//  Created by baiya on 2020/3/18.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_114_flatten_h
#define No_114_flatten_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TreeNode* flattenItem(TreeNode* node) {
//    if (!node) return node;
//    if (!node->left && !node->right) {
//        return node;
//    }
//    TreeNode *leftBegin = node->left;
//    TreeNode *rightBegin = node->right;
//    TreeNode *leftEnd = flattenItem(leftBegin);
//    TreeNode *rightEnd = flattenItem(rightBegin);
//    if (leftEnd) {
//        if (rightBegin) {
//            leftEnd->right = rightBegin;
//        } else {
//            rightEnd = leftEnd;
//        }
//
//        leftEnd->left = nullptr;
//        node->right = leftBegin;
//        node->left = nullptr;
//    } else {
//        node->right = rightBegin;
//        node->left = nullptr;
//    }
//
//    return rightEnd;
//}

TreeNode *pre = nullptr;

void flatten(TreeNode* root) {
//    flattenItem(root);
    if (root == nullptr)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = pre;
    root->left = nullptr;
    pre = root;
}

void testFlatten()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    flatten(root);
    while(root) {
        printf("%d,",root->val);
        root = root->right;
    }
}

#endif /* No_114_flatten_h */
