/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define PI 3.1415926

double angleByVectors(int x1, int y1, int x2, int y2) {
    int mul = x1 * x2 + y1 * y2;
    double len1 = std::sqrt(x1 * x1 + y1 * y1);
    double len2 = std::sqrt(x2 * x2 + y2 * y2);
    double cos = (double) (mul / (len1 * len2));
    return std::acos(cos);
}

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    double ans = angleByVectors(x1, y1, x2, y2);
    std::cout << std::setprecision(5) << std::fixed;
    std::cout << ans << std::endl;
    return 0;
}
