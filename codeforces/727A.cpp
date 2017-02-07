/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/727/submission/21466332 */

#include <bits/stdc++.h>

std::vector<int> path;

int main() {
    int a, b;
    std::cin >> a >> b;
    path.push_back(b);
    bool ans;
    while (b > a) {
        if ((b % 2) == 0) {
            b /= 2;
        } else if ((b % 10) == 1) {
            b = (b - 1) / 10;
        } else {
            break;
        }
        path.push_back(b);
    }
    if (b == a) {
        std::reverse(path.begin(), path.end());
        std::cout << "YES" << std::endl;
        std::cout << path.size() << std::endl;
        for (int i = 0; i < path.size(); i++) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
