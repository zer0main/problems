/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef long long int lint;

lint binpow(lint a, lint n, lint mod) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return (binpow(a, n - 1, mod) * a) % mod;
    } else {
        lint b = binpow(a, n / 2, mod) % mod;
        return (b * b) % mod;
    }
}

int main() {
    for (lint i = 1e9; i < 1e9 + 1001; i++) {
        std::cout << binpow(239, 1e9, i) << " ";
    }
    return 0;
}
