/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 100500

int input_arr[SIZE];
int sums[SIZE];
int n;

void returnBest() {
    int best = sums[0];
    int best_index = 1;
    for (int i = 1; i < n; i++) {
        if (sums[i] > best) {
            best = sums[i];
            best_index = i + 1;
        }
    }
    int start = 1;
    for (int i = 0; i < best_index - 1; i++) {
        if (sums[i] == 0) {
            start = i + 2;
        }
    }
    std::cout << start << " " << best_index << " "
              << best << std::endl;
}

void returnMax() {
    int max = input_arr[0];
    int max_index = 1;
    for (int i = 0; i < n; i++) {
        if (input_arr[i] > max) {
            max = input_arr[i];
            max_index = i + 1;
        }
    }
    std::cout << max_index << " " << max_index << " "
              << max << std::endl;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input_arr[i];
    }
    sums[0] = std::max(0, input_arr[0]);
    for (int i = 1; i < n; i++) {
        sums[i] = std::max(0, sums[i - 1] + input_arr[i]);
    }
    bool negative = true;
    for (int i = 0; i < n; i++) {
        if (sums[i] > 0) {
            negative = false;
        }
    }
    if (negative) {
        returnMax();
    } else {
        returnBest();
    }
    return 0;
}
