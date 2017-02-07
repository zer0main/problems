/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef long long int lint;

/* gcd means "greatest common divisor" */
lint gcd(lint a, lint b) {
    while (b) {
        lint temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    lint n, var;
    std::cin >> n >> var;
    lint ans = gcd(var, var);
    for (lint i = 1; i < n; i++) {
        std::cin >> var;
        ans = gcd(ans, var);
    }
    std::cout << ans << std::endl;
    return 0;
}
