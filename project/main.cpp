//
//  main.cpp
//  project
//
//  Created by HFY on 2019/11/20.
//  Copyright © 2019 nsblacker. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

//void reverse(char* str) {
//    char *begin = str;
//    char *end = str;
//    while (*end != '\0') {
//        end++;
//    }
//
//    while (begin < end) {
//        char tmp = *end;
//        end = begin;
//        *begin = tmp;
//
//        begin++;
//        end--;
//    }
//}

int solution_find_unique(int a[], int size) {
    if ((size & 1) == 0) {
        return 0;// size 为偶数
    }
    
    // a ^ 0 == a; a ^ a == 0
    int ret = 0;
    for (int i = 0; i < size; i++) {
        ret = ret ^ a[i];
    }
    
    return ret;
}

int solution_find_unique2(int a[], int size) {
    if ((size & 1) == 0) {
        return 0;// size 为偶数
    }
    std::map<int, int> countMap;
    for (int i = 0; i < size; i++) {
        int key = a[i];
        countMap[key]++;
    }
    
    int ret = 0;
    for (auto itor = countMap.begin(); itor != countMap.end(); itor++) {
        if ((*itor).second == 1) {
            ret = (*itor).first;
        }
    }
    
    return ret;
}

bool isLittleEndian() {
    int num = 0x8866;
    char b = ((char *)&num)[0];
    if (b == 0x66) {
        return true;
    }
    return false;
}

void printMatrix(std::vector<std::vector<int>> m) {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
