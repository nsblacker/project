//
//  SingleNumber.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/17.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

/**
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

 说明：

 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

 示例 1:

 输入: [2,2,1]
 输出: 1
 示例 2:

 输入: [4,1,2,1,2]
 输出: 4
 */
class SingleNumber {
                    
public:
    
    int singleNumber0(std::vector<int>& nums) {
        
        int ret = 0;
        for (int num : nums) {
            ret = ret ^ num;
        }
        return ret;
    }
    
    int singleNumber1(std::vector<int>& nums) {
        // map 统计个数
        std::unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        
        int ret = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second < 2) {
                ret = it->first;
                break;
            }
        }
        return ret;
    }

    
    int singleNumber2(std::vector<int>& nums) {
        // 先排序，再排查成对出现的情况
        std::sort(nums.begin(), nums.end());
        int ret = nums[0];
        int i = 1;
        for (;i < nums.size();) {
            if (nums[i] != nums[i - 1]){
                ret = nums[i - 1];
                break;
            } else {
                i = i + 2;
            }
        }
        if (i >= nums.size()) {
            //前面都是成对的，只能是最后一个是目标值
            ret = nums.back();
        }
        
        return ret;
    }
    
};
