/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/484/submission/13222716 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long long int l, r;
        std::cin >> l >> r;
        while ((l | (l + 1)) <= r) {
            l = l | (l + 1);
        }
        std::cout << l << std::endl;
    }
    return 0;
}
