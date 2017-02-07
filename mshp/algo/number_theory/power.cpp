/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef long long int lint;

lint PRECISION = (lint) 1e6;

lint myPower(lint a, lint b) {
    lint ans = 1;
    for (lint pw = 0; pw < b; pw++) {
        ans = ((a % PRECISION) * (ans % PRECISION)) % PRECISION;
    }
    return ans;
}

int main() {
    lint a, b;
    std::cin >> a >> b;
    std::cout << myPower(a, b) << std::endl;
    return 0;
}
