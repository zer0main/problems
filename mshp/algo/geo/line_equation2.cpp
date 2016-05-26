/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int main() {
    // point: x0, y0
    // normal vector: x1, y1
    int x0, y0, x1, y1;
    std::cin >> x0 >> y0 >> x1 >> y1;
    int A = x1;
    int B = y1;
    int C = -A * x0 - B * y0;
    std::cout << A << " " << B << " " << C << std::endl;
    return 0;
}
