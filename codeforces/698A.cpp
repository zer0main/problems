/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/698/submission/20152328 */

#include <bits/stdc++.h>

int main() {
    int n, prev, curr, ans = 0;
    std::cin >> n;
    std::cin >> prev;
    if (!prev) { ans++; }
    for (int i = 1; i < n; i++) {
        std::cin >> curr;
        if (!curr) {
            ans++;
        } else if ((curr != 3) && (prev == curr)) {
            curr = 0;
            ans++;
        } else if ((curr == 3) && (prev != 3)) {
            curr = 3 - prev;
        }
        prev = curr;
    }
    std::cout << ans << std::endl;
    return 0;
}
