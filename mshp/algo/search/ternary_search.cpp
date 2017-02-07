/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef long double LLD;

int Vp, Vf;
LLD Oy;

LLD getTime(LLD coordinate) {
    LLD field_dist = std::sqrt(
        coordinate * coordinate + (1 - Oy) * (1 - Oy)
    );
    LLD forest_dist = std::sqrt(
        (1 - coordinate) * (1 - coordinate) + Oy * Oy
    );
    return forest_dist / Vf + field_dist / Vp;
}

LLD ternarySearch(LLD l, LLD r) {
    while (r - l > 1e-15) {
        LLD m1 = l + (r - l) / 3;
        LLD m2 = r - (r - l) / 3;
        if ((getTime(m2) - getTime(m1)) > 1e-25) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return (l + r) / 2;
}

int main() {
    std::cin >> Vp >> Vf;
    std::cin >> Oy;
    std::cout << std::setprecision(9) << std::fixed;
    std::cout << ternarySearch(0, 1) << std::endl;
    return 0;
}
