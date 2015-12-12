/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef long long int lint;

int main() {
    lint N;
    std::cin >> N;
    double val = (-1 + std::sqrt(1 + 8 * N)) / 2.0;
    lint row = ((val - (int) val) == 0.0) ? val - 1 : val / 1;
    lint max = ((row + 2) * (row + 1)) / 2;
    lint x = ((row % 2) == 0) ? row - (max - N) : max - N;
    lint y = row - x;
    std::cout << x << " " << y << std::endl;
    return 0;
}
