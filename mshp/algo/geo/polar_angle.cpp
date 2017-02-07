/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define PI 3.1415926

int main() {
    int x, y;
    std::cin >> x >> y;
    double ans = std::atan2(y, x);
    ans = ((ans < 0) ? (2 * PI + ans) : ans);
    std::cout << std::setprecision(6) << std::fixed;
    std::cout << ans << std::endl;
    return 0;
}
