//
//  sword_03.cpp
//  SuanFa
//
//  Created by fengqingsong on 2021/4/27.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "sword_03.hpp"
#include <iostream>
using namespace::std;

//int main(void) {
//    int metrix[16] = {
//        1, 2, 8, 9,
//        2, 4, 9, 12,
//        4, 7, 10, 13,
//        6, 8, 11, 15
//    };
//    findNum(metrix, 4, 4, 7);
//    return 0;
//}

/**
 输入一个二维数组(每行从左到右递增，每列从上到下递增)和一个整数，判断数组中是否含有该整数。
 */
bool findNum(int *metrix, int rows, int columns, int number) {
    if (!metrix) {
        return false;
    }
    
    int curRow = 0;
    int curColumn = columns - 1;
    int curNum = 0;
    bool found = false;
    
    while (curRow < rows && curColumn >= 0) {
        curNum = metrix[curRow * columns + curColumn];
        if (number < curNum) {
            --curColumn;
        } else if (number > curNum) {
            ++curRow;
        } else {
            found = true;
            cout << curRow + 1 << "行" << " " << curColumn + 1 << "列" << endl;
            return found;
        }
    }
    return found;
}
