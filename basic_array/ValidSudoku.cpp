//
//  ValidSudoku.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/19.
//  Copyright © 2020 nsblacker. All rights reserved.
//




#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class ValidSudoku {
    
public:
    
    bool checkMap(unordered_map<char, int>& map) {
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second > 1) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //检查行
        unordered_map<char, int> rowMap;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    rowMap[ch]++;
                }
            }
            if (!checkMap(rowMap)) {
                return false;
            } else {
                rowMap.clear();
            }
        }
        //检查列
        unordered_map<char, int> colsMap;
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                char ch = board[i][j];
                if (ch != '.') {
                    colsMap[ch]++;
                }
            }
            if (!checkMap(colsMap)) {
                return false;
            } else {
                colsMap.clear();
            }
        }
        //检查小3宫格
        unordered_map<char, int> miniMap;
        for (int k = 0; k < 9; k++) {//遍历所有小宫格
            for (int row = 0; row < 3; row++) {
                for (int cols = 0; cols < 3; cols++) {
                    char ch = board[(k / 3) * 3 + row][(k % 3) * 3 + cols];
                    if (ch != '.') {
                        miniMap[ch]++;
                    }
                }
            }
            if (!checkMap(miniMap)) {
                return false;
            } else {
                miniMap.clear();
            }
        }
        
        return true;
    }
};
