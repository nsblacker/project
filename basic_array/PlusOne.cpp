//
//  PlusOne.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/17.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class PlusOne {
    
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int flag = 1;//是否带进位，初始是有进位的
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            
            if ((*it + flag) >= 10) {
                flag = 1;
                result.push_back(0);
            } else {
                result.push_back(*it + flag);
                flag = 0;
            }
        }
        
        if (flag == 1) {
            result.push_back(1);
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
    
};
