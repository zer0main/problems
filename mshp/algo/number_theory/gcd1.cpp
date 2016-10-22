/*
 * Copyright (C) 2015-2016 Pavel Dolgov
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

/* lcm means "least common multiple" */
lint lcm(lint a, lint b) {
    return (a * b) / gcd(a, b);
}

int main() {
    lint n, k;
    std::cin >> n >> k;
    std::cout << lcm(n, k) << std::endl;
    return 0;
}
