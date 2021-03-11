//
//
//  HeapSort.cpp
//  SuanFa
//
//  代码千万行，注释第一行！
//  编码不规范，同事泪两行。
//
//  Created by fqs on 2019/4/4.
//  Copyright © 2019 fqs. All rights reserved.
//
    

#include "HeapSort.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

// 从某个节点调整堆
void heapAdjust(int array[], int length, int node) {
    int nodeValue = array[node];
    int child = 2 * node + 1;
    
    while (child < length) {
        // 比较左右子节点，取大的那个
        if (child + 1 < length && array[child] < array[child + 1]) {
            child = child + 1;
        }
        
        // 是否需要与子节点交换
        if (array[child] > nodeValue) {
            array[node] = array[child];
            node = child;
            child = node * 2 + 1;
        } else {
            break;
        }
    }
    
    array[node] = nodeValue;
}

//堆排序
void heapSort(int array[], int length) {
    // 建立堆
    // 对于一个叶子节点可以默认其是堆结构，所以可以从最后一个叶子节点的父节点开始一步一步把数组调整为堆
    for (int node = length / 2 - 1; node >= 0; node--) {
        heapAdjust(array, length, node);
    }
    
    // 依次取出根节点(最小)，并重整堆结构
    for (int i = length - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapAdjust(array, i, 0);
    }
}

void test_HeapSort() {
    srand(unsigned(time(NULL)));
    
    int length = 8;
    int array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100;
    }
    
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    heapSort(array, length);
    
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
