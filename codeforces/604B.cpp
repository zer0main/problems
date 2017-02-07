/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/604/submission/14699600 */

#include <bits/stdc++.h>

#define SIZE 100500

int bells[SIZE];

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> bells[i];
    }
    int max = bells[n - 1];
    for (int i = 0; i < n - k; i++) {
        max = std::max(max,
                       bells[i] + bells[2 * (n - k) - i - 1]);
    }
    std::cout << max << std::endl;
    return 0;
}
