//
//  LengthOfLongestSubstring.cpp
//  Hello
//
//  Created by fengqingsong on 2021/3/10.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "LengthOfLongestSubstring.hpp"
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

// 滑动窗口 + set
/*
int Solution::lengthOfLongestSubstring(string s) {
    int length = (int)s.size();
    int i = 0, j = 0, maxL = 0;
    set<char> set;
    while (i < length && j < length) {
        if (set.find(s[j]) == set.end()) {
            set.insert(s[j++]);
            maxL = max(j - i, maxL);
        } else {
            set.erase(s[i++]);
        }
    }
    return maxL;
}
 */

// 滑动窗口 + map
int Solution::lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, ans = 0;
    map<char, int> charMap;
    while (j < s.size()) {
        if (charMap.find(s[j]) != charMap.end()) {
            i = max(i, charMap[s[j]] + 1);
        }
        charMap[s[j]] = j;
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
