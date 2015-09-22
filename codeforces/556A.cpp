/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/556/submission/13172851 */

#include <iostream>
#include <string>

int myAbs(int n) {
    return (n >= 0) ? n : -n;
}

int main() {
    std::string str;
    getline(std::cin, str);
    getline(std::cin, str);
    int n = str.size();
    int n0 = 0, n1 = 0;
    char buff;
    for (int i = 0; i < n; i++) {
        buff = str[i];
        bool one = (buff == '1');
        n0 += one ? 0 : 1;
        n1 += one ? 1 : 0;
    }
    std::cout << myAbs(n0 - n1) << std::endl;
    return 0;
}
