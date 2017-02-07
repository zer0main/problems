/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/591/submission/13878629 */

#include <bits/stdc++.h>

int main() {
    int l, p, q;
    std::cin >> l >> p >> q;
    double time = (double) l / (double) (p + q);
    std::cout << time * p << std::endl;
    return 0;
}
