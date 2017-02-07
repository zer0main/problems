/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/570/submission/13120174 */

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    typedef std::vector<int> Ints;
    Ints candidates(150, 0);
    for (int i = 1; i <= m; i++) {
        int winner, maximum;
        winner = -1;
        maximum = -1;
        for (int x = 1; x <= n; x++) {
            int vote;
            std::cin >> vote;
            if (vote > maximum) {
                maximum = vote;
                winner = x;
            }
        }
        candidates[winner]++;
    }
    int winner, maximum;
    winner = -1;
    maximum = -1;
    for (int i = 1; i <= n; i++) {
        if (candidates[i] > maximum) {
            maximum = candidates[i];
            winner = i;
        }
    }
    std::cout << winner << std::endl;
    return 0;
}
