/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/579/submission/13221934 */

#include <iostream>

int main() {
    int x;
    std::cin >> x;
    int result = 0;
    while (x) {
        bool odd = x & 1;
        if (odd) {
            result++;
        }
        x = x >> 1;
    }
    std::cout << result << std::endl;
    return 0;
}
