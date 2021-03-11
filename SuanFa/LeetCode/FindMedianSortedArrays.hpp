//
//  FindMedianSortedArrays.hpp
//  Hello
//
//  Created by fengqingsong on 2021/3/11.
//  Copyright © 2021 fqs. All rights reserved.
//

#ifndef FindMedianSortedArrays_hpp
#define FindMedianSortedArrays_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
private:
    double findMedian(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2, int end2, int k);
};

#endif /* FindMedianSortedArrays_hpp */
