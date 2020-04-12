//
//  No.61.rotateRight.h
//  LeetCode
//
//  61. 旋转链表
//  https://leetcode-cn.com/problems/rotate-list/
//  Created by baiya on 2020/4/13.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_61_rotateRight_h
#define No_61_rotateRight_h

#include "Utils.h"

ListNode* rotateRight(ListNode* head, int k) {
    if(head==0 || head->next==0) return head;
            
    int len = 1;
    ListNode *tail = head;
    while(tail->next){
        ++len;
        tail = tail->next;
    }
    tail->next = head;

    if(k %= len){
        for(int i=0; i<len-k; ++i) {
            tail = tail->next;
        }
    }
    ListNode *res = tail->next;
    tail->next = 0;
    return res;
    
}
#endif /* No_61_rotateRight_h */
