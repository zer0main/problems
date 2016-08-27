/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/691/submission/20152825 */

#include <bits/stdc++.h>

int main() {
    int n, counter = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int state;
        std::cin >> state;
        if (!state) { counter++; }
    }
    bool ok;
    if (n == 1) {
        ok = (counter == 0);
    } else {
        ok = (counter == 1);
    }
    std::cout << ((ok) ? "YES" : "NO") << std::endl;
    return 0;
}
