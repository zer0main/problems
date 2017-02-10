/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

std::string S, T, all;
std::vector<int> ans;

int prefixFunc() {
    ans.push_back(0);
    for (int i = 1; i < all.size(); i++) {
        int z = ans[i - 1];
        while (z > 0 && all[z] != all[i]) {
            z = ans[z - 1];
        }
        if (all[i] == all[z]) {
            ans.push_back(z + 1);
        } else {
            ans.push_back(0);
        }
    }
}

int main() {
    std::cin >> T >> S;
    int size = S.size();
    all = S + '#' + T;
    prefixFunc();
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == size) {
            std::cout << i - 2 * size << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
