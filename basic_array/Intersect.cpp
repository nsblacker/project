//
//  Intersect.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/17.
//  Copyright © 2020 nsblacker. All rights reserved.
//

/**
 给定两个数组，编写一个函数来计算它们的交集。

 示例 1:

 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 输出: [2,2]
 示例 2:

 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 输出: [4,9]
 说明：

 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
 我们可以不考虑输出结果的顺序。
 进阶:

 如果给定的数组已经排好序呢？你将如何优化你的算法？
 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 */
#include <stdio.h>
#include <vector>
#include <unordered_map>


using namespace std;

class Intersect {
    
public:
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        // 不在乎元素顺序， O(n ^ 2), 在num2中寻找num1中的匹配，如果找到，删掉num2中的元素，防止重复匹配
        vector<int> intersect;
        for (auto it1 = nums1.begin(); it1 != nums1.end(); it1++) {
            for (auto it2 = nums2.begin(); it2 != nums2.end(); ) {
                if (*it1 == *it2) {
                    intersect.push_back(*it1);
                    nums2.erase(it2);
                    break;
                } else {
                    it2++;
                }
            }
        }
        
        return intersect;
    }
    
   vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
       // 排序之后，游标
       std::sort(nums1.begin(), nums1.end());
       std::sort(nums2.begin(), nums2.end());
       
       vector<int> intersect;
       int i1 = 0, i2 = 0;
       while (i1 < nums1.size() && i2 < nums2.size()) {
           if (nums1[i1] == nums2[i2]) {
               intersect.push_back(nums1[i1]);
               i1++;
               i2++;
           } else if (nums1[i1] < nums2[i2]) {
               i1++;
           } else if (nums2[i2] < nums1[i1]) {
               i2++;
           }
       }
       return intersect;
   }
    
    vector<int> intersect3(vector<int>& nums1, vector<int>& nums2) {
        // 先对其中一个结合建立hash map， 之后在另个集合中查找m，效率最高
        vector<int> intersect;
        std::unordered_map<int, int> m;
        for (int num : nums1) {
            m[num]++;
        }
        
        for (int num : nums2) {
            if (m[num] >= 1) {
                intersect.push_back(num);
                m[num]--;
            }
        }
        return intersect;
    }
};
