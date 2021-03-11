//
//  TwoSum.cpp
//  Hello
//
//  Created by fengqingsong on 2021/3/10.
//  Copyright © 2021 fqs. All rights reserved.
//

#include "TwoSum.hpp"
using namespace std;

vector<int> Solution::twoSum(vector<int> &nums, int target) {
    map<int, int> numsMap;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        map<int, int>::iterator iter = numsMap.find(target - nums[i]);
        if (iter != numsMap.end()) {
            result.push_back(iter->second);
            result.push_back(i);
            return result;
        } else {
            numsMap[nums[i]] = i;
        }
    }
    return result;
}
