/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/557/submission/13221198 */

#include <iostream>

int min(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int n;
    std::cin >> n;
    int min1, max1, min2, max2, min3, max3;
    std::cin >> min1 >> max1;
    std::cin >> min2 >> max2;
    std::cin >> min3 >> max3;
    int fst = min(n - min2 - min3, max1);
    n -= fst;
    int snd = min(n - min3, max2);
    n -= snd;
    int thr = n;
    std::cout << fst << " " << snd << " " << thr
              << std::endl;
    return 0;
}
