//
//  ReverseString.cpp
//  BasicString
//
//  Created by HFY on 2020/1/21.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

class ReverseString {
public:
    
    void swap1 (char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }
    
    void swap2(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void reverseString(vector<char>& s) {
        //容器(有点慢)
        int left = 0;
        int right = (int)s.size() - 1;
        while (left < right) {
            swap1(s[left], s[right]);
            //swap2(&s[left], &s[right]);
            left++;
            right--;
        }
    }
    
    void reverseString2(vector<char>& s) {
        //更慢
        for (int i = 0, j = (int)s.size() - 1; i < j; i++,j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    
    void reverseString3(vector<char>& s) {
        //直接交换，已经是最快的了
        int left = 0;
        int right = (int)s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    
    void reverseString4(char *s, int sSize) {
        //c类型指针
        char *head = s;
        char *tail = s + (sSize - 1);
        while (tail > head) {
            char tmp = *head;
            *head = *tail;
            *tail = tmp;
            head++;
            tail--;
        }
    }
};

