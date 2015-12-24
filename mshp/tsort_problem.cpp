/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 100010

int N;
std::vector< std::vector<int> > g(SIZE);
std::vector<int> topsort_array;
bool open[SIZE];
int color[SIZE];

void dfs(int v) {
    color[v] = 1;
    for (size_t i = 0; i < g[v].size(); i++) {
        int next = g[v][i];
        // cycle: color[next] is 1
        if (color[next] == 0) {
            dfs(next);
        }
    }
    color[v] = 2;
    topsort_array.push_back(v);
}

void topsort() {
    for (int i = 0; i < N; i++) {
        color[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    std::reverse(topsort_array.begin(), topsort_array.end());
}

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        std::cin >> n;
        g[n - 1].push_back(i);
    }
    topsort();
    for (int i = 0; i < N; i++) {
        open[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int v = topsort_array[i];
        if (!open[v]) {
            ans++;
        }
        for (size_t j = 0; j < g[v].size(); j++) {
            open[g[v][j]] = true;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
