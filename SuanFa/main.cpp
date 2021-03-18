//
//  main.cpp
//  SuanFa
//
//  Created by fengqingsong on 2019/3/26.
//  Copyright © 2019 fqs. All rights reserved.
//

#include <iostream>

/*
 #include "TwoSum.hpp"
 void twoSum() {
     Solution s;
     vector<int> nums = { 6, 2, 9, 4, 1, 3 };
     vector<int> result = s.twoSum(nums, 5);
     for (int i = 0; i < result.size(); i++) {
         cout << result[i] << endl;
     }
 }
 */
/*
 #include "LengthOfLongestSubstring.hpp"
 void lengthOfLongestSubstring() {
     Solution s;
     cout << s.lengthOfLongestSubstring("cbbcdef") << endl;
     cout << s.lengthOfLongestSubstring("bbbbbcb") << endl;
     cout << s.lengthOfLongestSubstring("pwwkew") << endl;
 }
 */
/*
 #include "FindMedianSortedArrays.hpp"
 void findMedianSortedArrays() {
     Solution s;
     // 1, 2, [3], 4, 6
     vector<int> nums1 = { 1, 3 };
     vector<int> nums2 = { 2, 4, 6 };
     cout << s.findMedianSortedArrays(nums1, nums2) << endl;
     // 1, 2, [3, 4], 5, 6
     vector<int> nums3 = { 1, 3, 5 };
     vector<int> nums4 = { 2, 4, 6 };
     cout << s.findMedianSortedArrays(nums3, nums4) << endl;
     // 1, [2, 3], 4
     vector<int> nums5 = { 1 };
     vector<int> nums6 = { 2, 3, 4 };
     cout << s.findMedianSortedArrays(nums5, nums6) << endl;
     // 1, 2, 3, [4], 6, 8, 10
     vector<int> nums7 = { 1, 3 };
     vector<int> nums8 = { 2, 4, 6, 8, 10 };
     cout << s.findMedianSortedArrays(nums7, nums8) << endl;
     // 1, 2, 3, 4, 5, [6, 7], 8, 9, 10, 11, 12
     vector<int> nums9 = { 1, 2, 3, 4 };
     vector<int> nums10 = { 5, 6, 7, 8, 9, 10, 11, 12 };
     cout << s.findMedianSortedArrays(nums9, nums10) << endl;
 }
 */

#include "LongestPalindrome.hpp"

int main(int argc, const char * argv[]) {
    Solution s;
    s.longestPalindrome("hello world");
    
    return 0;
}



