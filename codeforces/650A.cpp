/* http://codeforces.com/problemset/submission/650/43914080 */

#include <bits/stdc++.h>

typedef std::pair<int, int> IntPair;

int main() {
    std::map<int, int> xs, ys;
    std::map<IntPair, int> points_matches;
    int n, x, y;
    std::cin >> n;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        ans += xs[x] + ys[y] - points_matches[IntPair(x, y)];
        xs[x]++;
        ys[y]++;
        points_matches[IntPair(x, y)]++;
    }
    std::cout << ans << std::endl;
    return 0;
}
