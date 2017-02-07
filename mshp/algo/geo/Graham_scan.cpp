/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

template<typename T1, typename T2>
class MyPair : public std::pair<T1, T2> {
public:
    MyPair() {
    }

    MyPair(T1 first, T2 second)
        : std::pair<T1, T2>(first, second) {
    }

    bool operator<(const MyPair& pair) const {
        typedef std::pair<const T1&, const T2&> MyConstPair;
        MyConstPair p0(this->second, -(this->first));
        MyConstPair p1(pair.second, -pair.first);
        return p0 < p1;
    }
};

typedef MyPair<int, int> IntPair;
typedef std::vector<IntPair> IntPairs;

// all points
IntPairs points;
// extreme point
IntPair starting_point;
// stack with points in convex hull (current state)
IntPairs stack;

// make vector from two points
IntPair makeVector(IntPair p0, IntPair p1) {
    IntPair vect(p1.first - p0.first, p1.second - p0.second);
    return vect;
}

// [a, b]; where a, b - vectors
int vectorMul(IntPair a, IntPair b) {
    return a.first * b.second - b.first * a.second;
}

int lastVectorsMul(IntPair next) {
    IntPair vect1 =
        makeVector(stack[stack.size() - 2], stack[stack.size() - 1]);
    IntPair vect2 =
        makeVector(stack[stack.size() - 1], next);
    return vectorMul(vect1, vect2);
}

double calculatePolarAngle(IntPair point) {
    return std::atan2(
        starting_point.second - point.second,
        starting_point.first - point.first
    );
}

bool polarComp(IntPair a, IntPair b) {
    double a_angle = calculatePolarAngle(a);
    double b_angle = calculatePolarAngle(b);
    if (std::fabs(b_angle - a_angle) < 1e-10) {
        // a_angle == b_angle
        int b_dist =
            std::pow((b.first - starting_point.first), 2) +
            std::pow((b.second - starting_point.second), 2);
        int a_dist =
            std::pow((a.first - starting_point.first), 2) +
            std::pow((a.second - starting_point.second), 2);
        return a_dist < b_dist;
    }
    return b_angle > a_angle;
}

bool changePolygon(int index) {
    return (stack.size() > 1) && (lastVectorsMul(points[index]) <= 0);
}

void removeExtra(int index) {
    while (changePolygon(index)) {
        stack.pop_back();
    }
}

void fillStack() {
    for (int i = 2; i < points.size(); i++) {
        removeExtra(i);
        stack.push_back(points[i]);
    }
    if (stack.size() > 2) {
        removeExtra(0);
    }
}

int main() {
    // number of points
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        points.push_back(IntPair(x, y));
    }
    std::sort(points.begin(), points.end());
    // erase repeats
    points.erase(unique(points.begin(), points.end()), points.end());
    // extreme point
    starting_point = points[0];
    std::sort(points.begin() + 1, points.end(), polarComp);
    for (int i = 0; i < 2; i++) {
        if (i < points.size()) {
            stack.push_back(points[i]);
        }
    }
    fillStack();
    std::cout << stack.size() << std::endl;
    for (int i = 0; i < stack.size(); i++) {
        std::cout << stack[i].first << " "
                  << stack[i].second << std::endl;
    }
    return 0;
}
