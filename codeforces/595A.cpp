/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/595/submission/14302773 */

#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int window1, window2;
            std::cin >> window1 >> window2;
            if (window1 || window2) {
                ans++;
            }

        }
    }
    std::cout << ans << std::endl;
    return 0;
}
