/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef long long int lint;
typedef std::pair<lint, lint> LintPair;
typedef std::vector<LintPair> LintPairs;

LintPairs factorization;

void getFactorization(lint number) {
    int n = 2;
    while ((n * n) <= number) {
        int counter = 0;
        while ((number % n) == 0) {
            number /= n;
            counter++;
        }
        if (counter != 0) {
            factorization.push_back(LintPair(n, counter));
        }
        n++;
    }
    if (number != 1) {
        factorization.push_back(LintPair(number, 1));
    }
}

int main() {
    lint number;
    std::cin >> number;
    getFactorization(number);
    for (int i = 0; i < factorization.size(); i++) {
        std::cout << factorization[i].first;
        if (factorization[i].second != 1) {
            std::cout << "^" << factorization[i].second;
        }
        if (i != (factorization.size() - 1)) {
            std::cout << "*";
        }
    }
    std::cout << std::endl;
    return 0;
}
