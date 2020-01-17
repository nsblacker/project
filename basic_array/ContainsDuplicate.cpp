//
//  ContainsDuplicate.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/17.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <vector>
#include <unordered_map>

using namespace std;


/**
 给定一个整数数组，判断是否存在重复元素。

 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

 示例 1:

 输入: [1,2,3,1]
 输出: true
 示例 2:

 输入: [1,2,3,4]
 输出: false
 示例 3:

 输入: [1,1,1,3,3,4,3,2,4,2]
 输出: true
 */
class ContainsDuplicate {
    
public:
    bool containsDuplicate1(vector<int>& nums) {
        // map记录 耗时比较多
        unordered_map<int, int> m;
        
        for (int num : nums) {
            m[num]++;
        }
        
        for (auto it = m.begin(); it != m.end(); it++){
            if (it->second > 1) {
                return true;
            }
        }
        return false;
    }
    
    // 耗时中等
    bool containsDuplicate2(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        // 异或
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] ^ nums[i - 1]) == 0) {
                return true;
            }
        }
        return false;
    }
    
    // 调整一下排序的时机，效率进一步提高
    bool containsDuplicate3(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        // 异或
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] ^ nums[i - 1]) == 0) {
                return true;
            }
        }
        return false;
    }
};
