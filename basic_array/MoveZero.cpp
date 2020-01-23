//
//  MoveZero.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/18.
//  Copyright © 2020 nsblacker. All rights reserved.
//

/**
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

 示例:

 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 说明:

 必须在原数组上操作，不能拷贝额外的数组。
 尽量减少操作次数。
 */
#include <stdio.h>
#include <vector>

using namespace std;

class MoveZero {
    
public:

    void moveZeroes(vector<int>& nums) {
        // 一边遍历，一边删除，一边统计，最后在尾部追加一定个数的0
        int zeroCount = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
            if (*it == 0) {
                nums.erase(it);
                zeroCount++;
            } else {
                it++;
            }
        }
        
        for (int j = 0; j < zeroCount; j++) {
            nums.push_back(0);
        }
    }
};
