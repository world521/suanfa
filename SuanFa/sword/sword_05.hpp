//
//  sword_05.hpp
//  SuanFa
//
//  Created by fengqingsong on 2021/4/29.
//  Copyright © 2021 fqs. All rights reserved.
//

#ifndef sword_05_hpp
#define sword_05_hpp

#include <stdio.h>

/// 从尾到头打印链表，要求不修改原链表的结构。
struct ListNode {
    int value;
    ListNode *next;
};
/// 通过栈
void printListReversingly(ListNode *head);
/// 通过递归
void printListReversingly_Recursively(ListNode *head);

#endif /* sword_05_hpp */
