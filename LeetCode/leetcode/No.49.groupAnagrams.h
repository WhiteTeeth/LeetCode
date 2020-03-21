//
//  No.49.groupAnagrams.h
//  LeetCode
//
//  49. 字母异位词分组
//  https://leetcode-cn.com/problems/group-anagrams/
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_49_groupAnagrams_h
#define No_49_groupAnagrams_h

#include <vector>
#include <string>

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    map<string, vector<string>> maps;
    for (string s : strs) {
        maps[sort(s.start(), s.end())].push_back(s);
    }
    for( auto it = maps.begin(); it != maps.end(); ++it ) {
        result.push_back( it->second );
    }
    return result;
}

#endif /* No_49_groupAnagrams_h */
