//
//  No.142.detectCycle.h
//  LeetCode
//
//  142. 环形链表 II
//  https://leetcode-cn.com/problems/linked-list-cycle-ii/
//  Created by baiya on 2020/3/17.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_142_detectCycle_h
#define No_142_detectCycle_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    ListNode *slow = head, *fast = head;
    do {
        slow = slow->next;
        if (fast->next) {
            fast = fast->next->next;
        } else {
            return NULL;
        }
        if (!fast) {
            return NULL;
        }
    } while (slow != fast);
    
    ListNode *start = head;
    while (start != fast) {
        start = start->next;
        fast = fast->next;
    }
    return start;
    
}

#endif /* No_142_detectCycle_h */
