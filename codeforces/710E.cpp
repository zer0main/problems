/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/710/submission/20094274 */

#include <bits/stdc++.h>

#define SIZE 10000005

typedef long long int lint;

lint min_time[SIZE];

int main() {
    lint n, x, y;
    std::cin >> n >> x >> y;
    // base
    min_time[1] = x;
    for (int i = 2; i <= n; i++) {
        if (!(i % 2)) {
            min_time[i] = std::min(
                min_time[i - 1] + x,
                min_time[i / 2] + y
            );
        } else {
            min_time[i] = std::min(
                min_time[i - 1] + x,
                min_time[i / 2 + 1] + y + x
            );
        }
    }
    std::cout << min_time[n] << std::endl;
    return 0;
}
