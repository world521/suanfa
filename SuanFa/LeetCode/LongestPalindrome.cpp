//
//  LongestPalindrome.cpp
//  SuanFa
//
//  Created by fengqingsong on 2021/3/18.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "LongestPalindrome.hpp"
#include <map>
#include <iostream>
#include <vector>

string Solution::longestPalindrome(string s) {
    map<char, vector<int>> charMap;
    int maxLen = 1, start = 0;
    for (int i = 0; i < s.size(); i++) {
        map<char, vector<int>>::iterator iter = charMap.find(s[i]);
        if (iter != charMap.end()) {
            vector<int> vec = iter->second;
            vec.push_back(i);
            vector<int>::iterator first = vec.begin();
            vector<int>::iterator last = vec.end() - 1;
            int curLen = *last - *first + 1;
            if (maxLen < curLen) {
                maxLen = curLen;
                start = *first;
            }
        } else {
            vector<int> vec;
            vec.push_back(i);
            charMap[s[i]] = vec;
        }
    }
    string res = s.substr(start, maxLen);
    cout << res << endl;
    return res;
}

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int i = 0, j = 0, resI = 0, resJ = 0;
//        map<char, int> charMap;
//        while (j < s.size()) {
//            map<char, int>::iterator iter = charMap.find(s[j]);
//            if (iter != charMap.end()) {
//                if (iter->second >= i && resJ - resI < j - iter->second) {
//                    resI = iter->second;
//                    resJ = j;
//                }
//                i = max(i, iter->second + 1);
//            }
//            charMap[s[j]] = j;
//            j++;
//        }
//        string res = s.substr(resI, resJ - resI + 1);
//        cout << res << endl;
//        return res;
//    }
//};
