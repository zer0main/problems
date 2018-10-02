/* http://codeforces.com/contest/1008/submission/43706803 */

#include <bits/stdc++.h>

int main() {
    int n, w, h, prev_h;
    std::cin >> n;
    bool possible = true;
    std::cin >> w >> h;
    h = std::max(w, h);
    for (int i = 1; i < n; i++) {
        prev_h = h;
        std::cin >> w >> h;
        int min = std::min(w, h);
        int max = std::max(w, h);
        if (max <= prev_h) {
            h = max;
            w = min;
        } else if (min <= prev_h) {
            h = min;
            w = max;
        } else {
            possible = false;
        }
    }
    std::cout << ((possible) ? "YES" : "NO") << std::endl;
    return 0;
}
