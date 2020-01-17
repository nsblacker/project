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

using namespace std;

void printIntArray(const vector<int> &num) {
    for (auto i: num) {
        cout << i << "\t";
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
    vector<int> nums = {0,0,0,3};
    MoveZero *mz = new MoveZero();
    mz->moveZeroes(nums);
    printIntArray(nums);
}


int main(int argc, const char * argv[]) {
    
    runMoveZeros();
    return 0;
}
