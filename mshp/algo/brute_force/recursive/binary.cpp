/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::vector<int> Ints;

void generate(int N, int K, Ints history) {
    if (N == 0) {
        for (int i = 0; i < history.size(); i++) {
            std::cout << history[i];
        }
        std::cout << std::endl;
        return;
    }
    if (K < N) {
        Ints new_history = history;
        new_history.push_back(0);
        generate(N - 1, K, new_history);
    }
    if (K > 0) {
        Ints new_history = history;
        new_history.push_back(1);
        generate(N - 1, K - 1, new_history);
    }
}

int main() {
    int N, K;
    std::cin >> N >> K;
    Ints history;
    generate(N, K, history);
    return 0;
}
