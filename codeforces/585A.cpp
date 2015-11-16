/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/585/submission/14303413 */

#include <bits/stdc++.h>

#define SIZE 4500

int v[SIZE];
int d[SIZE];
int p[SIZE];
int res_arr[SIZE];

int main() {
    int n, res = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i] >> d[i] >> p[i];
    }
    for (int i = 0; i < n; i++) {
        if (p[i] >= 0) {
            long long int cry_val = 0;
            res_arr[res] = i + 1;
            res++;
            for (int x = i + 1; x < n; x++) {
                if (p[x] < 0) {
                    continue;
                }
                p[x] -= cry_val + v[i];
                if (v[i] > 0) {
                    v[i]--;
                }
                if ((p[x] < 0) && (cry_val < 1e7)) {
                    cry_val += d[x];
                }
            }
        }
    }
    std::cout << res << std::endl;
    for (int i = 0; i < res; i++) {
        std::cout << res_arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
