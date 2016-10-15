/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/727/submission/21466910 */

#include <bits/stdc++.h>

std::vector<int> ans;

int getSum(int index1, int index2) {
    std::cout << "? " << index1 << " " << index2 << std::endl;
    std::cout.flush();
    int sum;
    std::cin >> sum;
    return sum;
}

void calculateFirst() {
    int sum1 = getSum(1, 2);
    int sum2 = getSum(1, 3);
    int sum3 = getSum(2, 3);
    ans.push_back((sum1 + sum2 - sum3) / 2);
    ans.push_back(sum1 - ans.back());
    ans.push_back(sum3 - ans.back());
}

int main() {
    int n;
    std::cin >> n;
    calculateFirst();
    for (int i = 4; i <= n; i++) {
        int sum = getSum(i - 1, i);
        ans.push_back(sum - ans.back());
    }
    std::cout << "! ";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
