/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/603/submission/14701274 */

#include <bits/stdc++.h>

int main() {
    int n;
    std::string str;
    std::cin >> n >> str;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (str[i] != str[i - 1]) {
            ans++;
        }
    }
    std::cout << ((n >= ans + 2) ? ans + 2 : n) << std::endl;
    return 0;
}
