//
//  TwoSum.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/21.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 最耗时
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ret = {i,j};
                    break;
                }
            }
        }
        return ret;
    }
    
    vector<int> twoSum2(vector<int>& nums, int target) {
        // nums[i]当做key，i作为value，放到map中，用target - nums[i]查找
        vector<int> ret;
        map<int, int>rec;
        for (int i = 0; i < nums.size(); i++) {
            rec.insert({nums[i],i});
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int findKey = target - nums[i];
            auto findIt = rec.find(findKey);
            if (findIt != rec.end() && findIt->second != i) {//防止在[5,3,7] target = 10这种下， 误找到5
                ret.push_back(i);
                ret.push_back(findIt->second);
                break;
            }
        }

        return ret;

    }
    
    vector<int> twoSum3(vector<int>& nums, int target) {
        // map替换为哈希表
        vector<int> ret;
        unordered_map<int, int>rec;
        for (int i = 0; i < nums.size(); i++) {
            rec.insert({nums[i],i});
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int findKey = target - nums[i];
            auto findIt = rec.find(findKey);
            if (findIt != rec.end() && findIt->second != i) {
                ret.push_back(i);
                ret.push_back(findIt->second);
                break;
            }
        }

        return ret;
    }
    
    vector<int> twoSum4(vector<int>& nums, int target) {
        // map替换为哈希表, 且只统计findKey的数目，而不需要find
        vector<int> ret;
        unordered_map<int, int>rec;
        for (int i = 0; i < nums.size(); i++) {
            rec.insert({nums[i],i});
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int findKey = target - nums[i];
            int keyCount = (int)rec.count(findKey);
            if (keyCount > 0 &&  rec[findKey] != i) {
                ret.push_back(i);
                ret.push_back(rec[findKey]);
                break;
            }
        }

        return ret;
    }
    
    
};
