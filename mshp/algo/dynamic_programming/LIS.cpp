/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 1050

int A[SIZE];

int D[SIZE];
int P[SIZE];

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int max = 0;
        P[i] = -1;
        for (int j = 0; j < i; j++) {
            if ((A[j] < A[i]) && (D[j] > max)) {
                max = D[j];
                P[i] = j;
            }
        }
        D[i] = max + 1;
    }
    int max = 0, max_index = 0;
    for (int i = 0; i < N; i++) {
        if (D[i] > max) {
            max = D[i];
            max_index = i;
        }
    }
    std::vector<int> res;
    while (max_index != -1) {
        res.push_back(A[max_index]);
        max_index = P[max_index];
    }
    std::reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    return 0;
}
