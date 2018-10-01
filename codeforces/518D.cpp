/* http://codeforces.com/contest/518/submission/43627738 */

#include <bits/stdc++.h>

#define MAX_N 2000
#define MAX_T 2000

double probabilities[MAX_T][MAX_N];

int main() {
    int n, t;
    double p, ans = 0;
    std::cin >> n >> p >> t;
    if (n >= t) {
        // Mean of binomial distribution.
        ans = t * p;
    } else {
        // Base.
        probabilities[0][0] = 1 - p;
        probabilities[0][1] = p;
        for (int i = 1; i < t; i++) {
            int max_folks = i + 1;
            if (max_folks > n) {
                max_folks = n;
            }
            for (int j = 0; j <= max_folks; j++) {
                double entered = 0;
                double stayed = probabilities[i - 1][j] * (1 - p);
                if (j == n) {
                    stayed = probabilities[i - 1][j];
                }
                if (j != 0) {
                    entered = probabilities[i - 1][j - 1] * p;
                }
                probabilities[i][j] = entered + stayed;
            }
        }
        for (int i = 0; i <= n; i++) {
            ans += probabilities[t - 1][i] * i;
        }
    }
    std::cout << std::setprecision(7) << std::fixed;
    std::cout << ans << std::endl;
    return 0;
}
