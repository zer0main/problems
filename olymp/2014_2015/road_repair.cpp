/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define MIN -100500

int main() {
    int L, N;
    std::cin >> L >> N;
    int last = MIN;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int state;
        std::cin >> state;
        if (state == 1) {
            if ((i - last + 1) > L) {
                last = i;
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
