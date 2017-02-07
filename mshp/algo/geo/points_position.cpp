/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int main() {
    // points coordinates
    int x0, y0, x1, y1;
    // line
    int A, B, C;
    std::cin >> x0 >> y0 >> x1 >> y1 >> A >> B >> C;
    bool p0_value = std::signbit((double) (A * x0 + B * y0 + C));
    bool p1_value = std::signbit((double) (A * x1 + B * y1 + C));
    std::cout << ((p0_value == p1_value) ? "YES" : "NO") << std::endl;
    return 0;
}
