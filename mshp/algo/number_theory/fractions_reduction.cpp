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
    lint a, b;
    std::cin >> a >> b;
    lint gcd_val = gcd(a, b);
    lint nominator = a / gcd_val;
    lint denominator = b / gcd_val;
    // stupid testing system doesn't understand that a / -b = -a / b
    if (denominator < 0) {
        nominator = -std::abs(nominator);
        denominator = std::abs(denominator);
    }
    std::cout << nominator << " " << denominator << std::endl;
    return 0;
}
