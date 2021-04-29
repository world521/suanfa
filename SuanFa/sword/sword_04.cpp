//
//  sword_04.cpp
//  SuanFa
//
//  Created by fengqingsong on 2021/4/27.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "sword_04.hpp"
#include <iostream>
using namespace std;

//int main() {
//    char str[32] = "hello world 123";
//    replaceBlank(str, 32);
//}

void replaceBlank(char str[], int length) {
    if (str == NULL || length >= 0) {
        return;
    }
    
    int originLen = 0;
    int blankCount = 0;
    
    int i = 0;
    while (str[i] != '\0') {
        ++ originLen;
        if (str[i] == ' ') {
            ++ blankCount;
        }
        i++;
    }
    
    int newLen = originLen + blankCount * 2;
    if (newLen > length) {
        return;
    }
    
    int index1 = originLen - 1;
    int index2 = newLen - 1;
    while (index1 >= 0) {
        if (str[index1] == ' ') {
            str[index2 --] = '0';
            str[index2 --] = '2';
            str[index2 --] = '%';
        } else {
            str[index2 --] = str[index1];
        }
        -- index1;
    }
    
    cout << str << endl;
}
