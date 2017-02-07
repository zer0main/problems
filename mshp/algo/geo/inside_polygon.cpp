/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> IntPairs;

int vectorMul(IntPair a, IntPair b) {
    return a.first * b.second - b.first * a.second;
}

int scalarMul(IntPair a, IntPair b) {
    return a.first * b.first + a.second * b.second;
}

int main() {
    // number of vertices and coordinates of starting point
    int N, x, y;
    std::cin >> N >> x >> y;
    // vectors for all vertices (starting point --> curr vertex)
    IntPairs vectors;
    for (int i = 0; i < N; i++) {
        // polygon vertex
        int vx, vy;
        std::cin >> vx >> vy;
        vectors.push_back(IntPair(vx - x, vy - y));
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        IntPair v1 = vectors[i];
        IntPair v2 = vectors[(i + 1) % N];
        sum += std::atan2(vectorMul(v1, v2), scalarMul(v1, v2));
    }
    bool outside = (std::fabs(sum) < 1e-9);
    std::cout << (outside ? "NO" : "YES") << std::endl;
    return 0;
}
