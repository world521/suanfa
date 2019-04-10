//
//  QuickSort.cpp
//  SuanFa
//
//  Created by fengqingsong on 2019/3/26.
//  Copyright © 2019 fqs. All rights reserved.
//

#include "QuickSort.hpp"
#include <iostream>
using namespace std;

void testQuickSort() {
    int length = 10;
    int array[10] = {9, 8, 6, 8, 0, 2, 4, 12, 10, 5};
    quickSort(array, 0, length - 1);
    for (int i = 0; i < length; i++) {
        cout << array[i] << endl;
    }
}

void quickSort(int *array, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int pivot = array[left];
    int i = left;
    int j = right;
    
    while (i < j) {
        while (i < j && array[j] >= pivot) {
            j--;
        }
        array[i] = array[j];
        
        while (i < j && array[i] <= pivot) {
            i++;
        }
        array[j] = array[i];
    }
    
    array[i] = pivot;
    
    quickSort(array, left, i - 1);
    quickSort(array, i + 1, right);
}
