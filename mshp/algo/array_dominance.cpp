/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 100500

typedef long long int llint;

llint A[SIZE];
llint B[SIZE];

bool myCmp(llint first, llint second) {
    return first > second;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }
    std::sort(A, A + n);
    std::sort(B, B + m, myCmp);
    llint ans = 0;
    int min_length = std::min(n, m);
    for (int i = 0; (i < min_length) && (A[i] < B[i]); i++) {
        ans += B[i] - A[i];
    }
    std::cout << ans << std::endl;
    return 0;
}
