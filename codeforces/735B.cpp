/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/735/submission/22785771 */

#include <bits/stdc++.h>

#define SIZE 100500

typedef long long int lint;

lint worth[SIZE];

int main() {
    lint n, n1, n2;
    std::cin >> n >> n1 >> n2;
    for (lint i = 0; i < n; i++) {
        std::cin >> worth[i];
    }
    std::sort(worth, worth + n);
    lint s1 = 0;
    for (lint i = 0; i < std::min(n1, n2); i++) {
        s1 += worth[n - i - 1];
    }
    lint s2 = 0;
    for (lint i = 1; i <= std::max(n1, n2); i++) {
        s2 += worth[n - std::min(n1, n2) - i];
    }
    double ans =
        (double) s1 / std::min(n1, n2) + (double) s2 / std::max(n1, n2);
    std::cout << std::setprecision(7) << std::fixed;
    std::cout << ans << std::endl;
    return 0;
}
