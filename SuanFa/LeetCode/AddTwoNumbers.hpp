//
//  AddTwoNumbers.hpp
//  Hello
//
//  Created by fengqingsong on 2021/3/10.
//  Copyright © 2021 fqs. All rights reserved.
//

#ifndef AddTwoNumbers_hpp
#define AddTwoNumbers_hpp

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif /* AddTwoNumbers_hpp */
