/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::pair<int, int> IntPair;

int scalarMul(IntPair a, IntPair b) {
    return a.first * b.first + a.second * b.second;
}

bool onSegment(int x0, int y0, int x1, int y1, int x2, int y2) {
    // Segment AB; point P(x0, y0) is on the line
    IntPair ap(x0 - x1, y0 - y1);
    IntPair ab(x2 - x1, y2 - y1);
    IntPair bp(x0 - x2, y0 - y2);
    IntPair ba(x1 - x2, y1 - y2);
    bool lower_border = scalarMul(ap, ab) >= 0;
    bool upper_border = scalarMul(bp, ba) >= 0;
    return lower_border && upper_border;
}

int main() {
    // point
    int x0, y0;
    // segment
    int x1, y1, x2, y2;
    std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    // line
    int A = y2 - y1;
    int B = x1 - x2;
    int C = -A * x1 - B * y1;
    bool on_line = ((A * x0 + B * y0 + C) == 0);
    bool on_segment = false;
    if (on_line) {
        if (onSegment(x0, y0, x1, y1, x2, y2)) {
            on_segment = true;
        }
    }
    std::cout << (on_segment ? "YES" : "NO") << std::endl;
    return 0;
}
