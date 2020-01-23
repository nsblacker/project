//
//  UniqueChar.cpp
//  BasicString
//
//  Created by HFY on 2020/1/21.
//  Copyright © 2020 nsblacker. All rights reserved.
//

/**
 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 案例:

 s = "leetcode"
 返回 0.

 s = "loveleetcode",
 返回 2.
  

 注意事项：您可以假定该字符串只包含小写字母。
 */
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class UniqueChar {
    
public:
    int firstUniqChar(string s) {
        // 统计个数 O(n)，效率中等偏下,但是可以处理通用情况，非局限小写字母
        int ret = -1;
        if (s.empty()) {
            return ret;
        }
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
    
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) {
                ret = i;
                break;
            }
        }
        return ret;
    }
    
    int firstUniqChar2(string s) {
        // 首尾同时统计，效率没有提高
        int ret = -1;
        int left = 0, right = (int)s.length() - 1;
        unordered_map<char, int> m;
        while (left <= right) {//需要等号，否则会漏掉，但是left==right时，不要重复统计
            if (left == right) {
                m[s[left]]++;
            }else {
                m[s[left]]++;
                m[s[right]]++;
            }
            left++;
            right--;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) {
                ret = i;
                break;
            }
        }
        
        return ret;
    }
    
    int firstUniqChar3(string s) {
        // 只处理小写字母（这是最优解思路，把vector替换纯的数组，还会更快）
        int ret = -1;
        vector<int> m(26,0);
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            m[ch - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i] - 'a'] == 1) {
                ret = i;
                break;
            }
        }
        
        return ret;
    }
};
