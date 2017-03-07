/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::vector<int> Ints;
typedef std::vector<char> Chars;
typedef std::vector<Ints> IntsVect;

// Numbers of vertices.
int N, S;
// Graph.
IntsVect g;

// For DFS.
Chars used;
// Current match.
Ints mt;

bool kuhns_algo(int vertex) {
    if (used[vertex]) {
        return false;
    }
    used[vertex] = true;
    for (int i = 0; i < g[vertex].size(); i++) {
        int to = g[vertex][i];
        if (mt[to] == -1 || kuhns_algo(mt[to])) {
            mt[to] = vertex;
            return true;
        }
    }
    return false;
}

int main() {
    std::cin >> N >> S;
    g.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S; j++) {
            int val;
            std::cin >> val;
            if (val) {
                g[i].push_back(j);
            }
        }
    }
    mt.assign(S, -1);
    for (int i = 0; i < N; i++) {
        used.assign(N, false);
        kuhns_algo(i);
    }
    int ans = 0;
    for (int i = 0; i < S; i++) {
        if (mt[i] != -1) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
