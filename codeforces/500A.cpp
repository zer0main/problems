/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/500/submission/13220211 */

#include <iostream>

int main() {
    int n, t;
    std::cin >> n >> t;
    bool possibility = false;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        int number;
        std::cin >> number;
        if (i == curr) {
            curr += number;
        }
        if (curr == t) {
            possibility = true;
        }
    }
    std::cout << (possibility ? "YES" : "NO") << std::endl;
    return 0;
}
