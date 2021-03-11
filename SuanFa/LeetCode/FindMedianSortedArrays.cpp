//
//  FindMedianSortedArrays.cpp
//  Hello
//
//  Created by fengqingsong on 2021/3/11.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "FindMedianSortedArrays.hpp"
#include <iostream>

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    if ((m + n) % 2 == 0) {
        return (findMedian(nums1, 0, m, nums2, 0, n, (m + n) / 2) + findMedian(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1)) * 0.5;
    } else {
        return findMedian(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
    }
}

double Solution::findMedian(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2, int end2, int k) {
    int m = end1 - start1;
    int n = end2 - start2;
    
    if (m <= 0) {
        return nums2[start2 + k - 1];
    } else if (n <= 0) {
        return nums1[start1 + k - 1];
    } else if (k == 1) {
        return min(nums1[start1], nums2[start2]);
    }
    
    int h = k / 2;
    int num1 = nums1[min(start1 + h - 1, end1 - 1)];
    int num2 = nums2[min(start2 + h - 1, end2 - 1)];
    if (num1 < num2) {
        return findMedian(nums1, start1 + h, end1, nums2, start2, end2, k - min(m, h));
    } else {
        return findMedian(nums1, start1, end1, nums2, start2 + h, end2, k - min(n, h));
    }
}

