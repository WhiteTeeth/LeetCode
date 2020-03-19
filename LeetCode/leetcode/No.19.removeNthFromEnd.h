//
//  No.19.removeNthFromEnd.h
//  LeetCode
//
//  19. 删除链表的倒数第N个节点
//  https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
//  Created by baiya on 2020/3/19.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_19_removeNthFromEnd_h
#define No_19_removeNthFromEnd_h

#include "Utils.h"


ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if (!head->next) return nullptr;
    ListNode* preHead = new ListNode(0);
    preHead->next = head;
    ListNode *firNode = preHead;
    ListNode *sndNode = preHead;
    int interval = 0;
    while (sndNode->next) {
        sndNode = sndNode->next;
        if (interval < n) {
            interval ++;
        } else {
            firNode = firNode->next;
        }
    }
    firNode->next = firNode->next->next;
    return preHead->next;
}

#endif /* No_19_removeNthFromEnd_h */
