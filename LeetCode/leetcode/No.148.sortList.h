//
//  No.148.sortList.h
//  LeetCode
//
//  148. 排序链表
//  https://leetcode-cn.com/problems/sort-list/
//  Created by baiya on 2020/3/24.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_148_sortList_h
#define No_148_sortList_h

#include "Utils.h"

//TODO 快慢指针找中点+归并排序

ListNode* twowayMerge(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    ListNode h(0);
    ListNode *head = &h;
    ListNode *p = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;

    }
    p->next = l1 == nullptr ? l2 : l1;
    return head->next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *mid = head;
    ListNode *fast = head;
    ListNode *pMid;
    while (fast && fast->next) {
        fast = fast->next->next;
        pMid = mid;
        mid = mid->next;
    }
    pMid->next = nullptr;
    
    return twowayMerge(sortList(head), sortList(mid));
}

#endif /* No_148_sortList_h */
