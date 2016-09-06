/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/689/submission/20425605 */

#include <bits/stdc++.h>

typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> IntPairs;

int getInt(char c) {
    return c - '0';
}

bool isCorrectIndex(const IntPair& index) {
    bool less = (index.first < 3) && (index.second < 3);
    bool greater = (index.first >= 0) && (index.second >= 0);
    bool base_index = less && greater;
    bool null_index = (index.first == 1) && (index.second == 3);
    return base_index || null_index;
}

IntPair getIndex(int val) {
    int x, y;
    if (val != 0) {
        if (val % 3) {
            x = val % 3 - 1;
            y = val / 3;
        } else {
            x = 2;
            y = val / 3 - 1;
        }
    } else {
        x = 1;
        y = 3;
    }
    return IntPair(x, y);
}

int main() {
    int n;
    std::string number;
    IntPairs indices;
    std::cin >> n >> number;
    int first = getInt(number[0]);
    for (int i = 0; i < n; i++) {
        int val = getInt(number[i]);
        indices.push_back(getIndex(val));
    }
    bool ans = true;
    for (int i = 0; i <= 9; i++) {
        IntPair index = getIndex(i);
        if (i != first) {
            int length = 1;
            while (length < n) {
                index.first +=
                    (indices[length].first - indices[length - 1].first);
                index.second +=
                    (indices[length].second - indices[length - 1].second);
                if (isCorrectIndex(index)) {
                    length++;
                } else {
                    break;
                }
            }
            if (length == n) {
                ans = false;
                break;
            }
        }
    }
    std::cout << ((ans) ? "YES" : "NO") << std::endl;
    return 0;
}
