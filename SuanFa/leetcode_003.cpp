//
//
//  leetcode_003.cpp
//  SuanFa
//
//  代码千万行，注释第一行！
//  编码不规范，同事泪两行。
//
//  Created by fqs on 2019/4/11.
//  Copyright © 2019 fqs. All rights reserved.
//
    

#include "leetcode_003.hpp"
#include <stdlib.h>
#include <time.h>

int lengthOfLongestSubstring(string s) {
    set<char> tmp;
    int maxLen = 0;
    int index = 0;
    int deleIndex = 0;

    while (index < s.size()) {
        if (tmp.find(s[index]) == tmp.end()) {
            tmp.insert(s[index++]);
            maxLen = max((int)tmp.size(), maxLen);
        } else {
            tmp.erase(s[deleIndex++]);
        }
    }
    
    return maxLen;
}


void test_lengthOfLongestSubstring() {
    string s = "abcdefabc";
    cout << lengthOfLongestSubstring(s) << endl;
}
