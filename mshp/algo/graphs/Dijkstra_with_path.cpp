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
int parent[SIZE];
bool u[SIZE];

int Dijkstra() {
    parent[start] = start;
    dist[start] = 0;
    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if (!u[j] && ((v == -1) || (dist[j] < dist[v]))) {
                v = j;
            }
        }
        if (v == finish) {
            return dist[v];
        }
        if (dist[v] == MAX_LENGTH) {
            break;
        }
        u[v] = true;
        for (int j = 0; j < N; j++) {
            if (g[v][j] && (dist[j] > (dist[v] + 1))) {
                parent[j] = v;
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
    int length = Dijkstra();
    int path[length + 1];
    int curr = finish;
    for (int i = length; i >= 0; i--) {
        path[i] = curr;
        curr = parent[curr];
    }
    std::cout << length << std::endl;
    if (length != 0) {
        for (int i = 0; i <= length; i++) {
            std::cout << path[i] + 1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
