/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/732/submission/22860690 */

#include <bits/stdc++.h>

typedef std::vector<int> Ints;
typedef std::vector<bool> Bools;
typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> IntPairs;

Ints preparation;
Ints days;

bool isGood(int last_day) {
    Bools teams(preparation.size(), false);
    IntPairs latest;
    for (int day = last_day; day >= 0; day--) {
        if (latest.size() == preparation.size()) {
            break;
        }
        if (days[day] > 0) {
            int team = days[day] - 1;
            if (!teams[team]) {
                teams[team] = true;
                latest.push_back(IntPair(day, preparation[team]));
            }
        }
    }
    if (latest.size() != preparation.size()) {
        return false;
    }
    std::reverse(latest.begin(), latest.end());
    int prev_date = 0;
    for (int i = 0; i < latest.size(); i++) {
        if ((latest[i].first - prev_date) >= latest[i].second) {
            prev_date += 1 + latest[i].second;
        } else {
            return false;
        }
    }
    return true;
}

int binarySearch(int l, int r) {
    if (!isGood(r)) {
        return -2;
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if (isGood(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n, m, curr;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> curr;
        days.push_back(curr);
    }
    for (int i = 0; i < m; i++)  {
        std::cin >> curr;
        preparation.push_back(curr);
    }
    std::cout << binarySearch(0, n - 1) + 1 << std::endl;
    return 0;
}
