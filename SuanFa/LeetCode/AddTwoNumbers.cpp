//
//  AddTwoNumbers.cpp
//  Hello
//
//  Created by fengqingsong on 2021/3/10.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "AddTwoNumbers.hpp"

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *sumList = NULL;
    ListNode *cur = NULL;
    int sum = 0;
    int carry = 0;
    while (l1 || l2) {
        if (l1 && l2) {
            sum = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1) {
            sum = l1->val;
            l1 = l1->next;
        } else {
            sum = l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        if (!cur) {
            sumList = cur =  new ListNode(sum, NULL);
        } else {
            cur->next = new ListNode(sum, NULL);
            cur = cur->next;
        }
    }
    if (carry) {
        cur->next = new ListNode(carry, NULL);
        cur = cur->next;
    }
    return sumList;
}
