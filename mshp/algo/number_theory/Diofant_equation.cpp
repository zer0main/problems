/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool findAnySolution(int a, int b, int c, int& x0, int& y0, int& g) {
    g = gcd(a, b, x0, y0);
    x0 *= c / g;
    y0 *= c / g;
    return !(c % g);
}

void findMinXSolution(int a, int b, int g, int x0, int y0) {
    int k = -(x0 * g) / b;
    while ((x0 + k * (b / g)) < 0) {
        k++;
    }
    std::cout << x0 + k * (b / g) << " " << y0 - k * (a / g) << std::endl;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int x0, y0, g;
    if (findAnySolution(a, b, c, x0, y0, g)) {
        findMinXSolution(a, b, g, x0, y0);
    } else {
        std::cout << "Impossible" << std::endl;
    }
    return 0;
}
