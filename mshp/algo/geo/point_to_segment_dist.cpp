/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::pair<double, double> DoublePair;

// point
int X0, Y0;
// segment
int X1, Y1, X2, Y2;
// line
int A, B, C;

bool pointOfLine(DoublePair point) {
    double factor = A * point.first + B * point.second + C;
    return std::fabs(factor) < 1e-10;
}

double vectorLength(DoublePair vector) {
    double square = std::pow(vector.first, 2) + std::pow(vector.second, 2);
    return std::sqrt(square);
}

double scalarMul(DoublePair a, DoublePair b) {
    return a.first * b.first + a.second * b.second;
}

double getLineDist(DoublePair point) {
    // Segment AB; point P(x, y) is on the line
    double x = point.first;
    double y = point.second;
    DoublePair ap(x - X1, y - Y1);
    DoublePair ab(X2 - X1, Y2 - Y1);
    DoublePair bp(x - X2, y - Y2);
    DoublePair ba(X1 - X2, Y1 - Y2);
    bool lower_border = scalarMul(ap, ab) >= 1e-10;
    bool upper_border = scalarMul(bp, ba) >= 1e-10;
    if (!lower_border || !upper_border) {
        return std::min(vectorLength(ap), vectorLength(bp));
    } else {
        return 0;
    }
}

DoublePair moveInDirection(DoublePair start, DoublePair vect, double dist) {
    double factor = dist / std::sqrt(A * A + B * B);
    DoublePair res(
        start.first + vect.first * factor,
        start.second + vect.second * factor
    );
    return res;
}

DoublePair getNearest(double dist) {
    DoublePair start(X0, Y0), normal1(A, B), normal2(-A, -B);
    DoublePair nearest1 = moveInDirection(start, normal1, dist);
    DoublePair nearest2 = moveInDirection(start, normal2, dist);
    if (pointOfLine(nearest1)) {
        return nearest1;
    } else {
        return nearest2;
    }
}

int main() {
    std::cin >> X0 >> Y0 >> X1 >> Y1 >> X2 >> Y2;
    // line
    A = Y2 - Y1;
    B = X1 - X2;
    C = -A * X1 - B * Y1;
    double dist = (A * X0 + B * Y0 + C) / std::sqrt(A * A + B * B);
    DoublePair nearest = getNearest(dist);
    double line_dist = getLineDist(nearest);
    double ans = std::sqrt(line_dist * line_dist + dist * dist);
    std::cout << std::setprecision(4) << std::fixed;
    std::cout << ans << std::endl;
    return 0;
}
