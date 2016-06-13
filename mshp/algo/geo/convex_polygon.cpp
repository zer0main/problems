/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::pair<int, int> IntPair;
typedef std::deque<IntPair> IntPairs;

IntPairs vertices;

// make vector from two points
IntPair makeVector(IntPair p0, IntPair p1) {
    IntPair vect(p1.first - p0.first, p1.second - p0.second);
    return vect;
}

// [a, b]; where a, b - vectors
int vectorMul(IntPair a, IntPair b) {
    return a.first * b.second - b.first * a.second;
}

int lastVectorsMul(int index0, int index1, int index2) {
    IntPair v1 = makeVector(vertices[index0], vertices[index1]);
    IntPair v2 = makeVector(vertices[index1], vertices[index2]);
    return vectorMul(v1, v2);
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        vertices.push_back(IntPair(x, y));
    }
    bool is_convex = true;
    bool is_positive = (lastVectorsMul(0, 1, 2) >= 0);
    for (int i = 1; i < N; i++) {
        bool curr = (lastVectorsMul(i, (i + 1) % N, (i + 2) % N) >= 0);
        if (is_positive != curr) {
            is_convex = false;
            break;
        }
        is_positive = curr;
    }
    std::cout << (is_convex ? "YES" : "NO") << std::endl;
    return 0;
}
