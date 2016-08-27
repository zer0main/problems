/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/706/submission/20093123 */

#include <bits/stdc++.h>

#define MY_INFINITY 1e15
#define SIZE 100500

typedef long long int lint;

lint min_energy[SIZE][2];
lint energy[SIZE];

std::string reverse(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> energy[i];
    }
    std::string prev, curr;
    std::cin >> prev;
    // dynamic base
    min_energy[0][0] = 0;
    min_energy[0][1] = energy[0];
    for (int i = 1; i < n; i++) {
        min_energy[i][0] = MY_INFINITY;
        min_energy[i][1] = MY_INFINITY;
        std::cin >> curr;
        if (curr >= prev) {
            min_energy[i][0] = std::min(
                min_energy[i - 1][0],
                min_energy[i][0]
            );
        }
        if (curr >= reverse(prev)) {
            min_energy[i][0] = std::min(
                min_energy[i - 1][1],
                min_energy[i][0]
            );
        }
        if (reverse(curr) >= prev) {
            min_energy[i][1] = std::min(
                min_energy[i - 1][0] + energy[i],
                min_energy[i][1]
            );
        }
        if (reverse(curr) >= reverse(prev)) {
            min_energy[i][1] = std::min(
                min_energy[i - 1][1] + energy[i],
                min_energy[i][1]
            );
        }
        prev = curr;
    }
    lint ans = std::min(min_energy[n - 1][0], min_energy[n - 1][1]);
    bool impossible = (ans == MY_INFINITY);
    std::cout << ((impossible) ? -1 : ans) << std::endl;
    return 0;
}
