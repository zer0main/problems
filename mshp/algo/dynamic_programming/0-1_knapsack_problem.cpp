/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 105
#define MAX_MASS 10500
#define MY_INFINITY 1000000

int mass[SIZE];
int cost[SIZE];

// index is mass
int best_cost[MAX_MASS];
std::vector<int> history[MAX_MASS];

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> mass[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> cost[i];
    }
    for (int i = 0; i <= M; i++) {
        best_cost[i] = -MY_INFINITY;
    }
    best_cost[0] = 0;
    int best_mass = 0;
    for (int i = 0; i < N; i++) {
        int m1 = mass[i];
        for (int m2 = M - m1; m2 >= 0; m2--) {
            int new_cost = best_cost[m2] + cost[i];
            int new_mass = m2 + m1;
            if (new_cost > best_cost[new_mass]) {
                history[new_mass] = history[m2];
                history[new_mass].push_back(i);
                best_cost[new_mass] = new_cost;
                if (best_cost[new_mass] > best_cost[best_mass]) {
                    best_mass = new_mass;
                }
            }
        }
    }
    std::vector<int> bb = history[best_mass];
    for (int i = 0; i < bb.size(); i++) {
        std::cout << (bb[i] + 1) << " ";
    }
    std::cout << std::endl;
    return 0;
}
