/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define MAX_LENGTH 1000000000

typedef std::vector<int> Ints;
typedef std::vector<bool> Bools;
typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> IntPairs;
typedef std::vector<IntPairs> IntPairsVect;

int N, edges_n, cities_n, start;
IntPairsVect g;
Ints dist, cities;
Bools used;

void Dijkstra() {
    dist[start] = 0;
    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if (!used[j] && ((v == -1) || (dist[j] < dist[v]))) {
                v = j;
            }
        }
        if (dist[v] == MAX_LENGTH) {
            break;
        }
        used[v] = true;
        for (int j = 0; j < g[v].size(); j++) {
            if (dist[g[v][j].first] > (dist[v] + g[v][j].second)) {
                dist[g[v][j].first] = dist[v] + g[v][j].second;
            }
        }
    }
}

int main() {
    std::cin >> N >> edges_n >> cities_n >> start;
    start--;
    g.resize(N);
    used.resize(N, false);
    dist.resize(N, MAX_LENGTH);
    for (int i = 0; i < cities_n; i++) {
        int city_n;
        std::cin >> city_n;
        cities.push_back(city_n - 1);
    }
    for (int i = 0; i < edges_n; i++) {
        int n1, n2, weight;
        std::cin >> n1 >> n2 >> weight;
        g[n1 - 1].push_back(IntPair(n2 - 1, weight));
        g[n2 - 1].push_back(IntPair(n1 - 1, weight));
    }
    Dijkstra();
    IntPairs ans;
    for (int i = 0; i < cities.size(); i++) {
        int d = dist[cities[i]];
        ans.push_back(IntPair(d, cities[i]));
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i].second + 1 << " " << ans[i].first << "\n";
    }
    return 0;
}
