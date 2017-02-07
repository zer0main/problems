/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>
#include <algorithm>

int maxPower(int* bears, int size, int group_size) {
    return bears[size - group_size];
}

int main() {
    int n;
    std::cin >> n;
    int* bears = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> bears[i];
    }
    std::sort(bears, bears + n);
    for (int x = 1; x <= n; x++) {
        int max_power = maxPower(bears, n, x);
        std::cout << max_power << std::endl;
    }
    delete[] bears;
    return 0;
}
