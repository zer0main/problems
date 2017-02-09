/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int main() {
    std::string input;
    std::vector<int> ans;
    std::cin >> input;
    ans.push_back(0);
    for (int i = 1; i < input.size(); i++) {
        int z = ans[i - 1];
        while (z > 0 && input[z] != input[i]) {
            z = ans[z - 1];
        }
        if (input[i] == input[z]) {
            ans.push_back(z + 1);
        } else {
            ans.push_back(0);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
