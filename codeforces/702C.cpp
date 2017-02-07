/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/702/submission/20289229 */

#include <bits/stdc++.h>

#define MY_INFINITY 2000000005

typedef std::vector<int> Ints;

int main() {
    int n, m, coordinate;
    Ints cities, towers;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> coordinate;
        cities.push_back(coordinate);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> coordinate;
        towers.push_back(coordinate);
    }
    int ans = -MY_INFINITY;
    for (int i = 0; i < n; i++) {
        int val = cities[i];
        Ints::iterator lower_nearest = std::lower_bound(
            towers.begin(),
            towers.end(),
            val
        );
        int dist;
        if (lower_nearest != towers.end()) {
            dist = *lower_nearest - val;
            if (lower_nearest != towers.begin()) {
                lower_nearest--;
                dist = std::min(dist, val - *lower_nearest);
            }
        } else {
            lower_nearest--;
            dist = val - *lower_nearest;
        }
        ans = std::max(ans, dist);
    }
    std::cout << ans << std::endl;
    return 0;
}
