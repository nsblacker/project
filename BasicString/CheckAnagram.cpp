//
//  CheckAnagram.cpp
//  BasicString
//
//  Created by HFY on 2020/1/22.
//  Copyright © 2020 nsblacker. All rights reserved.
//
/**
 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

 示例 1:

 输入: s = "anagram", t = "nagaram"
 输出: true
 示例 2:

 输入: s = "rat", t = "car"
 输出: false
 说明:
 你可以假设字符串只包含小写字母。

 进阶:
 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 */
#include <stdio.h>
#include <string>

using namespace std;

class CheckAnagram {
    
public:
    bool isAnagram(string s, string t){
        //效率中上
        int s_map[26] = {0};
        int t_map[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            s_map[s[i] - 'a']++;
        }
        
        for (int j = 0; j < t.length(); j++) {
            t_map[t[j] - 'a']++;
        }
        
        for (int k = 0; k < 26; k++){
            if (s_map[k] != t_map[k]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isAnagram2(string s, string t) {
        //效率最高，来自社区
        if(s.size() != t.size()){
            return false;
        }
        int sCnt[26] = {0};
        for(auto i : s){
            sCnt[i - 'a']++;
        }
        for(auto i : t){
            if((--sCnt[i - 'a']) < 0){
                return false;
            }
        }
        for(auto i : s){
            if(sCnt[i - 'a'] != 0){
                return false;
            }
        }
        return true;
    }
};
