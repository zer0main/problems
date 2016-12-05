/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 110
#define MAX_LENGTH 1000000000

int N, edges;
int G[SIZE][SIZE];

void FloydWarshall() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    std::cin >> N >> edges;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            G[i][j] = MAX_LENGTH;
        }
    }
    for (int i = 0; i < edges; i++) {
        int n1, n2, weight;
        std::cin >> n1 >> n2 >> weight;
        G[n1 - 1][n2 - 1] = weight;
        G[n2 - 1][n1 - 1] = weight;
    }
    FloydWarshall();
    int best_v = 1, best_dist = MAX_LENGTH;
    for (int i = 0; i < N; i++) {
        int curr_dist = -1;
        for (int j = 0; j < N; j++) {
            if (G[i][j] > curr_dist) {
                curr_dist = G[i][j];
            }
        }
        if (curr_dist >= MAX_LENGTH) {
            // Graph is not connected.
            best_v = 1;
            break;
        }
        if (curr_dist < best_dist) {
            best_v = i + 1;
            best_dist = curr_dist;
        }
    }
    std::cout << best_v << std::endl;
    return 0;
}
