/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::pair<double, double> DoublePair;
typedef std::vector<DoublePair> DoublePairs;

// circle
int x, y, r;
// line
int A, B, C;

bool pointOfLine(DoublePair point) {
    double factor = A * point.first + B * point.second + C;
    return std::fabs(factor) < 1e-10;
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
    DoublePair center(x, y), normal1(A, B), normal2(-A, -B);
    DoublePair nearest1 = moveInDirection(center, normal1, dist);
    DoublePair nearest2 = moveInDirection(center, normal2, dist);
    if (pointOfLine(nearest1)) {
        return nearest1;
    } else {
        return nearest2;
    }
}

int main() {
    std::cin >> x >> y >> r >> A >> B >> C;
    // distance from the center of the circle to the line
    double dist = std::abs(A * x + B * y + C) / std::sqrt(A * A + B * B);
    DoublePair nearest = getNearest(dist);
    DoublePairs ans;
    if (r > dist) {
        double path = std::sqrt(r * r - dist * dist);
        DoublePair direction1(B, -A);
        DoublePair direction2(-B, A);
        ans.push_back(moveInDirection(nearest, direction1, path));
        ans.push_back(moveInDirection(nearest, direction2, path));
    } else if (std::fabs(r - dist) < 1e-10) {
        // r == dist
        ans.push_back(nearest);
    }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); i++) {
        std::cout << std::setprecision(8) << std::fixed;
        std::cout << ans[i].first << " " << ans[i].second << std::endl;
    }
    return 0;
}
