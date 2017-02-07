/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int N, K;

void translate(int n) {
    std::vector<int> res(N, 1);
    int index = N - 1;
    while (n) {
        res[index--] = (n % K) + 1;
        n /= K;
    }
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin >> N >> K;
    int max = static_cast<int>(std::pow(K, N));
    for (int i = 0; i < max; i++) {
        translate(i);
    }
    return 0;
}
