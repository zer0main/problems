/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 105
#define MAX_MASS 10500

int gold[SIZE];

int D[MAX_MASS];

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> gold[i];
    }
    D[0] = 1;
    for (int i = 1; i <= M; i++) {
        D[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = M - gold[i]; j >= 0; j--) {
            D[j + gold[i]] |= D[j];
        }
    }
    int max = 0;
    for (int i = 0; i <= M; i++) {
        if (D[i] == 1) {
            max = i;
        }
    }
    std::cout << max << std::endl;
    return 0;
}
