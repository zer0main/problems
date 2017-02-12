/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::vector<int> Ints;

Ints z_function(const std::string& s) {
    int n = s.size();
    Ints z(n, 0);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i,  r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    std::string s;
    std::cin >> s;
    Ints z = z_function(s);
    for (int i = 0; i < z.size(); i++) {
        std::cout << z[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
