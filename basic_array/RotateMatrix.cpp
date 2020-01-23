//
//  RotateMatrix.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/20.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class RotateMatrix {
    
public:
    void swap(int &n1, int &n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    void rotateMatrix(vector<vector<int>>& matrix) {
        //找到了规律，先作转置，再按行reverse
        int n = (int)matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (auto it = matrix.begin(); it != matrix.end(); it++) {
            std::reverse(it->begin(), it->end());
        }
    }
};
