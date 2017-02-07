/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

const int N = 16000000;
int lp[N + 1];
int pr[N + 1];
int pr_size = 0;

int main() {
    int number;
    std::cin >> number;
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr[pr_size++] = i;
        }
        for (int j = 0; j < pr_size && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    std::cout << pr[number - 1] << std::endl;
    return 0;
}
