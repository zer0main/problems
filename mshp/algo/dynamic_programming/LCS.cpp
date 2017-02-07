/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 1050

int A[SIZE];
int B[SIZE];

int table[SIZE][SIZE];

int main() {
    int N, M;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            table[i][j] = 0;
            if ((i > 0) && (table[i - 1][j] > table[i][j])) {
                table[i][j] = table[i - 1][j];
            }
            if ((j > 0) && (table[i][j - 1] > table[i][j])) {
                table[i][j] = table[i][j - 1];
            }
            if ((i > 0) && (j > 0) && (A[i - 1] == B[j - 1])) {
                if ((table[i - 1][j - 1] + 1) > table[i][j]) {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
            }
        }
    }
    int x = N, y = M;
    std::vector<int> ans;
    while ((y > 0) || (x > 0)) {
        if ((x > 0) && (table[x - 1][y] == table[x][y])) {
            x--;
        } else if ((y > 0) && (table[x][y - 1] == table[x][y])) {
            y--;
        } else {
            ans.push_back(A[x - 1]);
            y--; x--;
        }
    }
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
