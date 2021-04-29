//
//  sword_05.cpp
//  SuanFa
//
//  Created by fengqingsong on 2021/4/29.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "sword_05.hpp"
#include <iostream>
#import <stack>
using namespace::std;

//int main() {
//    // 构建链表：0 1 2 3 4 5 6 7 8 9
//    ListNode *head = NULL;
//    ListNode *node = NULL;
//    for (int i = 0; i < 10; i++) {
//        if (!head) {
//            node = head = new ListNode();
//            node->value = i;
//        } else {
//            node->next = new ListNode();
//            node = node->next;
//            node->value = i;
//        }
//    }
//
//    // 倒序输出链表
////    printListReversingly(head);
//    printListReversingly_Recursively(head);
//    
//    // 释放链表
//    node = head;
//    ListNode *next = NULL;
//    while (node) {
//        next = node->next;
//        delete node;
//        node = next;
//    }
//}

/// 通过栈
void printListReversingly(ListNode *head) {
    stack<ListNode *> sk;
    
    ListNode *node = head;
    while (node) {
        sk.push(node);
        node = node->next;
    }
    
    while (!sk.empty()) {
        node = sk.top();
        sk.pop();
        cout << node->value << " ";
    }
}

/// 通过递归
/// 链表过长会导致函数调用层级很深，有函数调用栈溢出的风险
void printListReversingly_Recursively(ListNode *head) {
    if (head == NULL) {
        return;
    }
    
    if (head->next != NULL) {
        printListReversingly(head->next);
    }
    cout << head->value << " ";
}
