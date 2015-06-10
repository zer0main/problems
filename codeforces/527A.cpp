/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/527/submission/11525645 */

#include <iostream>

int main() {
    long long int a, b;
    std::cin >> a >> b;
    long long int ans = 0;
    while (b > 0) {
        ans += a / b;
        a = a % b;
        long long int temp = a;
        a = b;
        b = temp;
    }
    std::cout << ans << std::endl;
    return 0;
}
