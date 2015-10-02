/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/581/submission/13342071 */

#include <iostream>

int min(int n1, int n2) {
    return (n1 > n2) ? n2 : n1;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << min(a, b) << " ";
    int remain = (a + b - 2 * min(a, b));
    std::cout << remain / 2 << std::endl;
    return 0;
}
