/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

// See snake.txt
#include <bits/stdc++.h>

typedef long long int lint;

int main() {
    lint N;
    std::cin >> N;
    double val = (-1.0 + std::sqrt(1.0 + 8.0 * N)) / 2.0;
    lint diag = ((val - lint(val)) == 0.0) ? val - 1 : val / 1;
    lint max = ((diag + 2) * (diag + 1)) / 2;
    lint x = ((diag % 2) == 0) ? (diag - (max - N)) : (max - N);
    lint y = diag - x;
    std::cout << x << " " << y << std::endl;
    return 0;
}
