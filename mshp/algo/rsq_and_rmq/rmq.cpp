/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::vector<int> Ints;

int main() {
    int N, K;
    std::cin >> N;
    int sqrt_len = (int) std::sqrt(N) + 1;
    Ints input(N, 0);
    Ints sqrt_arr(sqrt_len, 0);
    for (int i = 0; i < N; i++) {
        int curr;
        std::cin >> curr;
        input[i] = curr;
    }
    int max = input[0];
    for (int i = 0; i < N; i++) {
        if ((i % sqrt_len) == 0) {
            max = input[i];
        }
        if (input[i] >= max) {
            sqrt_arr[i / sqrt_len] = input[i];
            max = input[i];
        }
    }
    std::cin >> K;
    for (int j = 0; j < K; j++) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        int max = input[l];
        int n_block = l / sqrt_len;
        for (int i = l; i <= r; ) {
            bool less = (i + sqrt_len - 1) <= r;
            bool start_block = (i % sqrt_len) == 0;
            if (less && start_block) {
                if (sqrt_arr[i / sqrt_len] > max) {
                    max = sqrt_arr[i / sqrt_len];
                    n_block = i / sqrt_len;
                }
                i += sqrt_len;
            } else {
                if (input[i] > max) {
                    max = input[i];
                    n_block = i / sqrt_len;
                }
                i++;
            }
        }
        int max_index;
        for (int i = 0; i < sqrt_len; i++) {
            if (input[sqrt_len * n_block + i] == max) {
                max_index = sqrt_len * n_block + i;
                break;
            }
        }
        std::cout << max << " " << max_index + 1 << std::endl;
    }
    return 0;
}
