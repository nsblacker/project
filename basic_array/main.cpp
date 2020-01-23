//
//  main.cpp
//  BasicArray
//
//  Created by HFY on 2020/1/17.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <iostream>
#include "Stock.cpp"
#include "RemoveDuplicate.cpp"
#include "Rotate.cpp"
#include "ContainsDuplicate.cpp"
#include "SingleNumber.cpp"
#include "Intersect.cpp"
#include "PlusOne.cpp"
#include "MoveZero.cpp"
#include "ValidSudoku.cpp"
#include "RotateMatrix.cpp"
#include "TwoSum.cpp"

using namespace std;

void printIntArray(const vector<int> &num) {
    for (auto i: num) {
        cout << i << "\t";
    }
    cout << endl;
}

void printIntMatrix(const vector<vector<int>> & matrix) {
    for (auto line : matrix) {
        printIntArray(line);
    }
    cout << endl;
}

void runStock() {
    vector<int> prices = {7,6,4,3,1};
    Solution *s = new Solution();
    cout << s->maxProfit(prices) << endl;
}

void runRemoveDuplicate() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    RemoveDuplicate *rd = new RemoveDuplicate();
    cout << rd->removeDuplicates(nums) << endl;
}

void runRotate() {
    vector<int> nums = {-1};
    int k = 2;
    
    Rotate *r = new Rotate();
    r->rotate1(nums, k);
    printIntArray(nums);
}

void runContainDup() {
    vector<int> nums = {0,1,2,3,4,0};
    ContainsDuplicate *cd = new ContainsDuplicate();
    cout << (cd->containsDuplicate2(nums) == true ? "YES Duplicate Elements" : "NO Duplicate Elements") << endl;
}

void runSingleuNum() {
    vector<int> nums = {2,2,1};
    SingleNumber *sn = new SingleNumber();
    cout << sn->singleNumber2(nums) << endl;
}

void runIntersect() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    
    Intersect *i = new Intersect();
    printIntArray(i->intersect3(nums1, nums2));
}

void runPlusOne() {
    vector<int> digit = {1,2,3};
    PlusOne *po = new PlusOne();
    printIntArray(po->plusOne(digit));
}

void runMoveZeros() {
    vector<int> nums = {1,0,0,3};
    MoveZero *mz = new MoveZero();
    mz->moveZeroes(nums);
    printIntArray(nums);
}

void runValidSudoku() {
    vector<char> line1 = {'5','3','.','.','7','.','.','.','.'};
    vector<char> line2 = {'6','.','.','1','9','5','.','.','.'};
    vector<char> line3 = {'.','9','8','.','.','.','.','6','.'};
    vector<char> line4 = {'8','.','.','.','6','.','.','.','3'};
    vector<char> line5 = {'4','.','.','8','.','3','.','.','1'};
    vector<char> line6 = {'7','.','.','.','2','.','.','.','6'};
    vector<char> line7 = {'.','6','.','.','.','.','2','8','.'};
    vector<char> line8 = {'.','.','.','4','1','9','.','.','5'};
    vector<char> line9 = {'.','.','.','.','8','.','.','7','9'};
    vector<vector<char>> board = {line1,line2,line3,line4,line5,line6,line7,line8,line9};
    ValidSudoku *vs = new ValidSudoku();
    
    cout << (vs->isValidSudoku(board) == true ? "YES Valid Sudoku" : "NO Invalid Sudoku") << endl;
}

void runRotateMatrix() {
    
    vector<vector<int>> matrix =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {12,13,14,15}
    };
    RotateMatrix *rm = new RotateMatrix();
    rm->rotateMatrix(matrix);
    printIntMatrix(matrix);
}

void runTwoSum() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    TwoSum *ts = new TwoSum();
    vector<int> ret = ts->twoSum4(nums, target);
    printIntArray(ret);
}


int main(int argc, const char * argv[]) {
    
    runTwoSum();
    return 0;
}
