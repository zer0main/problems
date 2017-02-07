/*
 * Copyright (C) 2015-2017 Pavel Dolgov
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
    lint a, p;
    std::cin >> a >> p;
    std::cout << binpow(a, p - 2, p) << std::endl;
    return 0;
}
