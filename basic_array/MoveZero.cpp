//
//  MoveZero.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/18.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <vector>

/**
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

 示例:

 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 说明:

 必须在原数组上操作，不能拷贝额外的数组。
 尽量减少操作次数。
 */
using namespace std;

class MoveZero {
    
public:
    void moveZeroes(vector<int>& nums) {
        //0 向后移动
        
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == 0) {
//                for (int j = i; j < nums.size() - 1; j++) {
//                    nums[j] = nums[j + 1];
//                }
//                nums[nums.size() - 1] = 0;
//            }
//        }
    }
    
    //非0向前移动
};
