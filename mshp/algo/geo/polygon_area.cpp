/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define MY_INFINITY 10000000

typedef std::pair<int, int> DoublePair;
typedef std::deque<DoublePair> DoublePairs;

DoublePairs vertices;
DoublePair starting_point;

// make vector from two points
DoublePair makeVector(DoublePair p0, DoublePair p1) {
    DoublePair vect(p1.first - p0.first, p1.second - p0.second);
    return vect;
}

// [a, b]; where a, b - vectors
double vectorMul(DoublePair a, DoublePair b) {
    return a.first * b.second - b.first * a.second;
}

double lastVectorsMul(int index0, int index1) {
    DoublePair v1 = makeVector(starting_point, vertices[index0]);
    DoublePair v2 = makeVector(starting_point, vertices[index1]);
    return vectorMul(v1, v2);
}

int main() {
    int N;
    std::cin >> N;
    int max_x = -MY_INFINITY;
    int max_y = -MY_INFINITY;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        vertices.push_back(DoublePair(x, y));
        max_x = std::max(max_x, x);
        max_y = std::max(max_y, y);
    }
    starting_point = std::make_pair(max_x + 1, max_y + 1);
    double area = 0.0;
    for (int i = 0; i < N; i++) {
        area += lastVectorsMul(i, (i + 1) % N) / 2;
    }
    std::cout << std::setprecision(4) << std::fixed;
    std::cout << std::fabs(area) << std::endl;
    return 0;
}
