/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int main() {
    int x0, y0, x1, y1;
    std::cin >> x0 >> y0 >> x1 >> y1;
    int A = y1 - y0;
    int B = x0 - x1;
    int C = -A * x0 - B * y0;
    std::cout << A << " " << B << " " << C << std::endl;
    return 0;
}
