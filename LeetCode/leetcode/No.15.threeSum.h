//
//  No.15.threeSum.h
//  LeetCode
//  No.15. 三数之和
//  https://leetcode-cn.com/problems/3sum/
//  Created by baiya on 2020/2/27.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_15_threeSum_h
#define No_15_threeSum_h
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    map<string, int> cache;    // first is min, second is mid
    int N = (int)nums.size();
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int a = 0, b = a + 1, c = N -1;
    int fa = 0;
    while (a < c - 1) {
        if (fa != 0 && nums[fa] == nums[a]) {
            a++;
            continue;
        }
        int fb = 0;
        fa = a;
        b = a + 1;
        c = N -1;
        while (b < c) {
            int sum = nums[a] + nums[b] + nums[c];
            if (sum < 0) {
                b ++;
            } else if (sum > 0) {
                c--;
            } else {
                if (fb == 0 || nums[fb] != nums[b]) {
                    fb = b;
                    vector<int> item = {nums[a], nums[b], nums[c]};
                    result.push_back(item);
                    b++;
                    c--;
                } else {
                    b ++;
                }
            }
        }
        a++;
    }
    return result;
}

#endif /* No_15_threeSum_h */
