//
//
//  MergeSort.cpp
//  SuanFa
//
//  代码千万行，注释第一行！
//  编码不规范，同事泪两行。
//
//  Created by fqs on 2019/4/9.
//  Copyright © 2019 fqs. All rights reserved.
//
    

#include "MergeSort.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void merge(int array[], int left[], int leftCount, int right[], int rightCount) {
    int i = 0, j = 0, k = 0;
    
    while (i < leftCount && j < rightCount) {
        if (left[i] < right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }
    
    while (i < leftCount) {
        array[k++] = left[i++];
    }
    
    while (j < rightCount) {
        array[k++] = right[j++];
    }
}

void mergeSort(int array[], int length) {
    if (length == 1) {
        return;
    }
    
    int mid = length / 2;
    
    int *left = new int[mid];
    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    
    int *right = new int[length - mid];
    for (int i = mid; i < length; i++) {
        right[i - mid] = array[i];
    }
    
    mergeSort(left, mid);
    mergeSort(right, length - mid);
    
    merge(array, left, mid, right, length - mid);
}

void test_mergeSort() {
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
    
    mergeSort(array, length);
    
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


