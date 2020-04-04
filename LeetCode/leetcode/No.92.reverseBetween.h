//
//  No.92.reverseBetween.h
//  LeetCode
//
//  92. 反转链表 II
//  https://leetcode-cn.com/problems/reverse-linked-list-ii/
//  Created by baiya on 2020/4/4.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_92_reverseBetween_h
#define No_92_reverseBetween_h

#include "Utils.h"

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) return head;
    ListNode *end = head;
    ListNode *beforeEnd = nullptr;
    for (int i = 1; i < m-1; i++) {
        end = end->next;
    }
    if (m != 1) {
        beforeEnd = end;
        end = end->next;
    }
    
    ListNode *start = end->next;
    ListNode *tmp;
    ListNode *last = end;
    for (int j = m; j < n; j++) {
        tmp = start->next;
        start->next = last;
        last = start;
        start = tmp;
    }
    if (!beforeEnd) {
        head = last;
    } else {
        beforeEnd->next = last;
    }
    end->next = start;
    return head;
}

#endif /* No_92_reverseBetween_h */
