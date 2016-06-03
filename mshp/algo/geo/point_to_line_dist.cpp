/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int main() {
    // point
    int x, y;
    // line
    int A, B, C;
    std::cin >> x >> y >> A >> B >> C;
    double dist = (A * x + B * y + C) / std::sqrt(A * A + B * B);
    std::cout << std::setprecision(5) << std::fixed;
    std::cout << std::fabs(dist) << std::endl;
    return 0;
}
