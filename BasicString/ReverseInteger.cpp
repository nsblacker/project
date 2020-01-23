//
//  ReverseInteger.cpp
//  BasicString
//
//  Created by HFY on 2020/1/21.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ReverseInteger {
    
public:
    
    int reverse(int x) {
        
        bool flag = x < 0 ? true : false;
        int64_t lx = x;
        if (flag) lx = -lx;
        
        string num_string;
        while (lx!=0) {
            int a = lx % 10;//当前个位数
            char ch = '0' + a;
            num_string += ch;
            lx /= 10;
        }
        
        int64_t num = atol(num_string.c_str());
        if (flag) {
            num = -num;
        }
        
        if (num > INT_MAX || num < INT_MIN) {
            return 0;
        }
        
        return (int)num;
    }
    
    int reverse2(int x) {
        //用数组存每一位；校验是否出界，只需要比较long long型与int型是否相等
        return 0;
    }
};
