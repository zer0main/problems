/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/701/submission/20094628 */

#include <bits/stdc++.h>

typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> IntPairs;

IntPairs cards;

bool myComp(IntPair a, IntPair b) {
    return a.first < b.first;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        IntPair pair(val, i);
        cards.push_back(pair);
    }
    std::sort(cards.begin(), cards.end(), myComp);
    for (int i = 0; i < n / 2; i++) {
        std::cout << cards[i].second + 1 << " "
                  << cards[n - i - 1].second + 1 << std::endl;
    }
    return 0;
}
