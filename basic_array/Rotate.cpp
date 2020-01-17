//
//  Rotate.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/17.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <vector>

using namespace std;
/**
 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 示例 1:

 输入: [1,2,3,4,5,6,7] 和 k = 3
 输出: [5,6,7,1,2,3,4]
 解释:
 向右旋转 1 步: [7,1,2,3,4,5,6]
 向右旋转 2 步: [6,7,1,2,3,4,5]
 向右旋转 3 步: [5,6,7,1,2,3,4]
 示例 2:

 输入: [-1,-100,3,99] 和 k = 2
 输出: [3,99,-1,-100]
 解释:
 向右旋转 1 步: [99,-1,-100,3]
 向右旋转 2 步: [3,99,-1,-100]
 说明:

 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 要求使用空间复杂度为 O(1) 的 原地 算法。
 */
class Rotate {
public:
    
    void reverse(vector<int>& nums, int head, int tail){
        while (head < tail) {
            int temp = nums[head];
            nums[head] = nums[tail];
            nums[tail] = temp;
            head++;
            tail--;
        }
    }
    void rotate1(vector<int>& nums, int k) {
        // 局部旋转，在整体旋转
        if (nums.empty()) {
            return;
        }
        
        int len = (int)nums.size();
        int real_k = k % len;
        
        reverse(nums, 0, len - 1 - real_k);
        
        reverse(nums, len - real_k, len - 1);
        
        reverse(nums, 0, len - 1);
    }
    
    void rotate2(vector<int>& nums, int k) {
        // move one by one(Time Exceed Error)
        if (nums.empty()) {
            return;
        }

        int len = (int)nums.size();
        int real_k = k % len;
        
        for (int i = 0; i < real_k; i++) {
            int head = nums[len - 1];
            for (int j = len - 1; j >= 0; j--) {
                if (j == 0) {
                    nums[j] = head;
                } else {
                    nums[j] = nums[j - 1];
                }
            }
        }
    }
};
