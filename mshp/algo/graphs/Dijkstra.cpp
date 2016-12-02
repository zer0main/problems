/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 110
#define MAX_LENGTH 1000000000

int N, start, finish;
int g[SIZE][SIZE];
int dist[SIZE];
bool u[SIZE];

int Dijkstra() {
    dist[start] = 0;
    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if (!u[j] && ((v == -1) || (dist[j] < dist[v]))) {
                v = j;
            }
        }
        if (dist[v] == MAX_LENGTH) {
            break;
        }
        if (v == finish) {
            return dist[v];
        }
        u[v] = true;
        for (int j = 0; j < N; j++) {
            if (g[v][j] && (dist[j] > (dist[v] + 1))) {
                dist[j] = dist[v] + 1;
            }
        }
    }
    return -1;
}

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> g[i][j];
        }
    }
    std::cin >> start >> finish;
    start--; finish--;
    for (int i = 0; i < N; i++) {
        u[i] = false;
        dist[i] = MAX_LENGTH;
    }
    std::cout << Dijkstra() << std::endl;
    return 0;
}
