/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int main() {
    int A0, B0, C0, A1, B1, C1;
    std::cin >> A0 >> B0 >> C0 >> A1 >> B1 >> C1;
    // A0x + B0y + C0 = 0
    // A1x + B1y + C1 = 0
    double y = (double) (A1 * C0 - C1 * A0) / (double) (B1 * A0 - A1 * B0);
    double x;
    if (A0 == 0) {
        x = (double) (-C1 - B1 * y) / (double) A1;
    } else {
        x = (double) (-C0 - B0 * y) / (double) A0;
    }
    std::cout << std::setprecision(6) << std::fixed;
    std::cout << x << " " << y << std::endl;
    return 0;
}
