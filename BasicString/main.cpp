//
//  main.cpp
//  BasicString
//
//  Created by HFY on 2020/1/21.
//  Copyright © 2020 nsblacker. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include "ReverseString.cpp"
#include "ReverseInteger.cpp"
#include "UniqueChar.cpp"
#include "CheckAnagram.cpp"

using namespace std;

void printString(const string & s) {
    for (char ch : s){
        cout << ch << "\t";
    }
    cout << endl;
}

void printCharString(const char *s, int sSize) {
    for (int i = 0; i < sSize; i++) {
        cout << *(s + i) << "\t";
        //cout << s[i] << "\t";
    }
    cout << endl;
}

void printCharArray(const vector<char> s) {
    for (char ch : s){
        cout << ch << "\t";
    }
    cout << endl;
}

void runReverseString() {
    vector<char> s = {'h','e','l','l','o'};
    ReverseString *rs = new ReverseString();
    rs->reverseString3(s);
    printCharArray(s);
}

void runReverseInt() {
    int num = -2147483648;
    ReverseInteger *ri = new ReverseInteger();
    cout << "reverse:" << ri->reverse(num) << endl;
}

void runUniqueChar() {
    string s = "dddccdbba";
    UniqueChar *uc = new UniqueChar();
    cout << uc->firstUniqChar3(s) << endl;
}

void runCheckAnagram(){
    string s = "";
    string t = "aaa";
    CheckAnagram *ca = new CheckAnagram();
    cout << (ca->isAnagram(s, t) ? "true" : "false") << endl;
}

int main(int argc, const char * args[]) {
    //cout << args[0] << endl;
    runCheckAnagram();
    return 0;
}
